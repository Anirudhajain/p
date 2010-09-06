#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <pinocchio.h>
#include <lib/lib.h>
#include <system/ast/NativeMethod.h>

/* ========================================================================= */

static Symbol SMB_pPrimitive_plugin_;
static Symbol SMB_pPrimitive_plugin_code_;

/* ========================================================================= */

NativeMethod new_NativeMethod_with(Array params,
                                   Array locals,
                                   Array annotations,
    				               Array threaded,
                                   uns_int statementCount, ...)
{
    NEW_ARRAY_OBJECT(NativeMethod, Optr[statementCount]);
    result->params = params;
    result->locals = locals;
    result->annotations = annotations;
    init_variable_array(result->params, 0);
    init_variable_array(result->locals, result->params->size);
    result->info   = empty_Info;
    result->size   = statementCount;
    result->code = NULL;
    COPY_ARGS(statementCount, result->body);
    return result;
}

/* ========================================================================= */

native lookup_native(Optr primitive_name, Optr module_name)
{
    Optr module = IdentityDictionary_lookup(_NATIVES_, module_name);
    if (module == NULL) { return (native)-1; }
    if (HEADER(module) == (Class)Plugin_Plugin_Class) {
        module = ((Object)module)->ivals[2]; 
    }
    Optr primitive = IdentityDictionary_lookup(
                        (IdentityDictionary)module, primitive_name);
    if (primitive == NULL) { return (native)-1; }
    return (native)primitive;
}

void NativeMethod_invoke(MethodClosure closure,
                         NativeMethod method,
                         Optr self, uns_int argc)
{
    if (method->code == NULL) {
        Annotation annotation =
            lookup_annotation(method->annotations, 
                              (Optr)SMB_pPrimitive_plugin_);
        if (annotation == NULL) {
            annotation = lookup_annotation(method->annotations,
                              (Optr)SMB_pPrimitive_plugin_code_);
        }
        assert1(annotation, "No primitive annotation found");
        assert1(annotation->size == 2 || annotation->size == 3, "Invalid annotation format");
        method->code = lookup_native(annotation->arguments[0],
                                     annotation->arguments[1]);
    }
    if (method->code == (native)-1) {
        assert1(NULL, "Alternatives to native methods currently aren't supported!");
    }
    method->code(self, closure->host, argc);
}

/* ========================================================================= */

void post_init_NativeMethod() 
{
    SMB_pPrimitive_plugin_ = new_Symbol(L"pPrimitive:plugin:");
    SMB_pPrimitive_plugin_code_ = new_Symbol(L"pPrimitive:plugin:code:");
}
