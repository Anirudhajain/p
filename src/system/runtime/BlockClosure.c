#include <stdlib.h>
#include <stdio.h>
#include <system/runtime/BlockClosure.h>

/* ========================================================================= */

Runtime_BlockClosure new_Runtime_BlockClosure(Block code, 
                                              Runtime_BlockContext context) {
    NEW_OBJECT(Runtime_BlockClosure);
    assert1(HEADER(context) == Runtime_BlockContext_Class ||
            HEADER(context) == Runtime_MethodContext_Class,
            "Wrong type of context!");
    result->code      = code;
    result->context   = context;
    context->captured = 1;
    return result;
}

/* ========================================================================= */

Runtime_BlockContext activation_from_native(uns_int argc)
{
    Runtime_BlockClosure closure = current_env()->closure;
    Block block = closure->code;
    uns_int paramc = block->params->size;
    uns_int localc = block->locals->size;

    //assert1(argc == paramc, "Catch-all arguments not supported yet!");

    Runtime_BlockContext context = current_env();

    while (argc > 0) {
        argc--;
        context->locals[argc] = pop_EXP();
    }
    zap_EXP(); // remove self

    argc = paramc;
    // Set locals to nil.
    while (argc < paramc + localc) {
        context->locals[argc] = nil;
        argc++;
    }

    return context;
}

static void CNT_Block_continue()
{
    Runtime_BlockContext env = current_env();
    Block code = env->closure->code;
    uns_int pc = (uns_int)peek_EXP(1);
    poke_EXP(0, code->body[pc]);
    poke_EXP(1, ++pc);
    
    if (code->size <= pc) {
        poke_CNT(tail_send_Eval);
    } else { 
        push_CNT(send_Eval);
    }
}

static void start_eval(Block block)
{
    if (1 < block->size) {
        push_CNT(Block_continue);
        push_CNT(send_Eval);
    } else {
        push_CNT(tail_send_Eval);
    }
    
    poke_EXP(0, 1);
    push_EXP(block->body[0]);
}

static void CNT_Block_inline_continue()
{
    Block code = (Block)peek_EXP(2); 
    uns_int pc = (uns_int)peek_EXP(1);
    Optr exp = code->body[pc];
    pc += 1;
    
    if (pc < code->size) {
        poke_EXP(1, pc);
        push_CNT(send_Eval);
    } else { 
        zapn_EXP(2);
        poke_CNT(send_Eval);
    }

    poke_EXP(0, exp);
}

static void start_inline_eval(Block block)
{
    if (1 < block->size) {
        poke_EXP(0, block);
        push_EXP(1);
        push_CNT(Block_inline_continue);
        push_EXP(block->body[0]);
    } else {
        poke_EXP(0, block->body[0]);
    }
    push_CNT(send_Eval);
}

CNT(restore_pop_env)
    set_env(peek_EXP(1));
    Optr result = pop_EXP();
    poke_EXP(0, result);
}

void Runtime_BlockClosure_apply(Runtime_BlockClosure closure, uns_int argc)
{
    Block block = closure->code;
    assert1(argc == block->params->size, "Argument count mismatch");

    if (block->size == 0) { 
        RETURN_FROM_NATIVE(nil);
        return; 
    }

    /*
    if (block->locals->size == 0 && argc == 0) {
        Runtime_BlockContext env = current_env();
        if (env != closure->context) {
            poke_EXP(1, current_env());
            push_CNT(restore_pop_env);
            set_env(closure->context);
        } else {
            zap_EXP();
        }
        return start_inline_eval(block);
    }
    */
    
    set_env((Optr)new_Runtime_BlockContext(closure));
    activation_from_native(argc);

    push_CNT_raw(block->threaded);
    push_CNT_raw(0);
    push_CNT(eval_threaded);
    zap_EXP();
    CNT_eval_threaded();
    //start_eval(block);
}

void apply(Optr closure, uns_int argc)
{
    assert0(HEADER(closure) == Runtime_BlockClosure_Class);
    Runtime_BlockClosure_apply((Runtime_BlockClosure)closure, argc);
}

CNT(check_while_true)
    Optr boolean = peek_EXP(0);

    if (boolean == (Optr)true) {
        Optr closure = peek_EXP(1);
        poke_EXP(0, nil);
        push_EXP(closure);
        Runtime_BlockClosure_apply((Runtime_BlockClosure)closure, 0);
        return;
    }

    if (boolean == (Optr)false) {
        zap_CNT();
        zapn_EXP(3);
        poke_EXP(0, nil);
        return;
    }
    
    assert1(NULL, "Non-boolean type receiver for truth");
}

void CNT_while_true()
{
    Optr self = peek_EXP(2);
    push_CNT(check_while_true);
    poke_EXP(0, nil);
    push_EXP(self);
    Runtime_BlockClosure_apply((Runtime_BlockClosure)self, 0);
}

/* ========================================================================= */

NATIVE1(Runtime_BlockClosure_whileTrue_)
    push_CNT(while_true);
    push_CNT(check_while_true);
    push_EXP(nil);
    push_EXP(self);
    Runtime_BlockClosure_apply((Runtime_BlockClosure)self, 0);
}

NATIVE(Runtime_BlockClosure_apply_)
    Runtime_BlockClosure closure = (Runtime_BlockClosure)self;
    Runtime_BlockClosure_apply(closure, argc);
}

NATIVE0(Runtime_BlockClosure_numArgs) 
    RETURN_FROM_NATIVE(new_SmallInt(((Runtime_BlockClosure) self)->code->params->size));
}

NATIVE1(Runtime_BlockClosure_valueWithArguments_)
    Array args = (Array)pop_EXP();
    ASSERT_TAG_LAYOUT(GETTAG(args), Array);

    long pos = 0;
    while(pos < args->size) {
        push_EXP(args->values[pos]);
        pos++;
    }
    
    Runtime_BlockClosure closure = (Runtime_BlockClosure)self;
    Runtime_BlockClosure_apply(closure, args->size);
}

/* ========================================================================= */

void post_init_Runtime_BlockClosure()
{
    Dictionary natives = add_plugin(L"Reflection.Reflection");
    store_native(natives, SMB_blockclosureValue_message_, NM_Runtime_BlockClosure_apply_);
    store_native(natives, SMB_blockclosureValueWithArguments_message_,
                          NM_Runtime_BlockClosure_valueWithArguments_);
    natives = add_plugin(L"Runtime.BlockClosure");
    store_native(natives, SMB_numArgs, NM_Runtime_BlockClosure_numArgs);
    store_native(natives, new_Symbol_cached(L"whileTrue:"), NM_Runtime_BlockClosure_whileTrue_);
}
