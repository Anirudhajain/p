#include <system.h>
#include <thread.h>

void ifixed_dispatcher() {
    debug("an_ifixed>>dispatcher\n");
    context_object context = get_context();
    object self = context->self;
    object interp = header(self.pointer);
    object ifixed = (object)(pointer)*PINC(interp.pointer);

    set_argument(return_context(context), 1, ifixed.ifixed->delegate);
    pop_context();
    debug("ret>>an_ifixed>>dispatcher\n");
}

static void ifixed_at_do() {
    debug("an_ifixed>>at\n");
    context_object context = get_context();

    object self = context->self;
    object interp = header(self.pointer);
    ifixed_object ifixed = (ifixed_object)*PINC(interp.pointer);

    object idx = argument_at(context, 1);
    // XXX breaks encapsulation.
    int index = number_value(idx.number);
    int size = number_value(ifixed->size.number);
    debug("at %i (size %i)\n", index, size);

    assert(0 <= index);
    assert(index < size);
    
    set_argument(return_context(context), 1, object_at(self.object, index));
    pop_context();
    debug("ret>>an_ifixed>>at\n");
}

static void inline ifixed_at() {
    debug("an_ifixed>>at(pre)\n");
    context_object ifixed_context = get_context();
    assert_argsize(ifixed_context, 2);
    push_eval_of(ifixed_context, 1);
    ifixed_context->code = &ifixed_at_do;
    debug("ret>>an_ifixed>>at(pre)\n");
}

static void ifixed_at_put_do() {
    context_object context = get_context();
    assert_argsize(context, 3);

    object self = context->self;
    object interp = header(self.pointer);
    ifixed_object ifixed = (ifixed_object)*PINC(interp.pointer);

    object idx = argument_at(context, 1);
    // XXX breaks encapsulation.
    int index = number_value(idx.number);
    int size = number_value(ifixed->size.number);
    debug("an_ifixed>>atput (%i of %i)\n", index, size);

    assert(0 <= index);
    assert(index < size);
    
    object value = argument_at(context, 2);
    object_at_put(self.object, index, value);

    pop_context();
    debug("ret>>an_ifixed>>atput\n");
}

static void inline ifixed_at_put() {
    debug("an_ifixed>>atput(pre)\n");
    context_object ifixed_context = get_context();
    assert_argsize(ifixed_context, 2);
    push_eval_of(ifixed_context, 1);
    push_eval_of(ifixed_context, 2);
    ifixed_context->code = &ifixed_at_put_do;
    debug("ret>>an_ifixed>>atput(pre)\n");
}

void ifixed_dispatch() {

    debug("ifixedShiftLevel\n");
    
    context_object context = get_context();

    if (context_size(context) >= 1) {
        object selector = message(context);
        if_selector(selector, DELEGATE,         ifixed_dispatcher);
        if_selector(selector, OBJECT_AT,        ifixed_at);
        if_selector(selector, OBJECT_AT_PUT,    ifixed_at_put);
    }

    fallback_shift(context);

    debug("ret>>ifixedShiftLevel\n");
}

static void inline ifixed_size() {
    debug("ifixed>>size\n");
    context_object context = get_context();
    ifixed_object ifixed = context->self.ifixed;
    set_argument(return_context(context), 1, ifixed->size);
    pop_context();
    debug("ret>>ifixed>>size\n");
}

static void inline ifixed_new() {
    debug("ifixed>>new\n");
    // XXX breaking encapsulation of the number. should
    // check it's actually a number!
    context_object context = get_context();
    ifixed_object ifixed = context->self.ifixed;
    int size = number_value(ifixed->size.number);
    object_object instance = make_object(size, ifixed->interp);
    set_argument(return_context(context), 1, (object)instance);
    pop_context();
    debug("ret>>ifixed>>new\n");
}

void ifixed_class_dispatch() {
    context_object context = get_context();
    assert_argsize(context, 1);
    object selector = message(context);
    if_selector(selector, NEW,      ifixed_new);
    if_selector(selector, SIZE,     ifixed_size);
    /* Other messages sent bounce off to the delegate. */
    new_target(context, context->self.ifixed->delegate);
}

// ifixed_class>>dispatch:delegate:size:
static void ifixed_class_new_do() {
    debug("ifixedcls>>dispatch:delegate:size:\n");
    context_object ifixed_context = get_context();
    object ifixed =
        make_class(
            argument_at(ifixed_context, 1),  // dispatch
            argument_at(ifixed_context, 2),  // delegate
            argument_at(ifixed_context, 3),  // size
            &ifixed_dispatch);

    set_argument(return_context(ifixed_context), 1, ifixed);
    debug("ret>>ifixedcls>>dispatch:delegate:size:\n");
    pop_context();
}

// ifixed_class>>dispatch:delegate:size:(pre)
static void ifixed_class_new() {
    debug("ifixedcls>>(pre)\n");
    context_object ifixed_context = get_context();
    assert_argsize(ifixed_context, 4);
    push_eval_of(ifixed_context, 1);
    push_eval_of(ifixed_context, 2);
    push_eval_of(ifixed_context, 3);
    ifixed_context->code = &ifixed_class_new_do;
    debug("ret>>ifixedcls>>(pre)\n");
}

void ifixed_metaclass_dispatch() {
    context_object context = get_context();
    assert_argsize(context, 1);
    object selector = message(context);
    if_selector(selector, DISPATCH_DELEGATE_SIZE, ifixed_class_new);
    doesnotunderstand("ifixed_class", selector);
}

static void ifixed_stub_set_delegate_do() {
    debug("ifixed_stub>>delegate:\n");
    context_object context = get_context();
    ifixed_object ifixed = context->self.ifixed;
    ifixed->delegate = argument_at(context, 1);
    *pheader(ifixed) = &ifixed_class_dispatch;
    pop_context();
    debug("ret>>ifixed_stub>>delegate:\n");
}

static void inline ifixed_stub_set_delegate() {
    context_object context = get_context();
    assert_argsize(context, 2);
    push_eval_of(context, 1);
    context->code = &ifixed_stub_set_delegate_do;
}

static void ifixed_stub_dispatch() {
    context_object context = get_context();
    assert_argsize(context, 1);
    object selector = message(context);
    if_selector(selector, NEW,          ifixed_new);
    if_selector(selector, SIZE,         ifixed_size);
    if_selector(selector, SET_DELEGATE, ifixed_stub_set_delegate)
    /* TODO check if it makes sense to fall back to class */
    doesnotunderstand("ifixed_stub_class", selector);
}

// ifixed_class>>dispatch:delegate:size:
static void ifixed_stub_class_new_do() {
    debug("ifixed_stubcls>>dispatch:size:\n");
    context_object ifixed_context = get_context();
    object ifixed =
        make_class(
            argument_at(ifixed_context, 1),  // dispatch
            (object)fools_system->nil,       // delegate
            argument_at(ifixed_context, 2),  // size
            &ifixed_dispatch);

    *pheader(ifixed.pointer) = &ifixed_stub_dispatch;

    set_argument(return_context(ifixed_context), 1, ifixed);
    debug("ret>>ifixed_stubcls>>dispatch:size:\n");
    pop_context();
}

// ifixed_stub_class>>dispatch:size:(pre)
static void inline ifixed_stub_class_new() {
    debug("ifixed_stubcls>>(pre)\n");
    context_object ifixed_context = get_context();
    assert_argsize(ifixed_context, 3);
    push_eval_of(ifixed_context, 1);
    push_eval_of(ifixed_context, 2);
    ifixed_context->code = &ifixed_stub_class_new_do;
    debug("ret>>ifixed_stubcls>>(pre)\n");
}

void ifixed_stub_class_dispatch() {
    context_object context = get_context();
    assert_argsize(context, 1);
    object selector = message(context);
    if_selector(selector, DISPATCH_SIZE, ifixed_stub_class_new);
    doesnotunderstand("ifixed_stub_class", selector);
}

// Object creation
object make_class(object dispatch, object delegate, object size,
                  transfer_target cdispatch) {
    new_instance(ifixed);
    result->delegate        = delegate;
    result->size            = size;
    result->interp          = (object)make_object(2, dispatch);
    object_at_put(result->interp.object, 0, (object)cdispatch);
    object_at_put(result->interp.object, 1, (object)result);
    return (object)result;
}
