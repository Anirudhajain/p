#ifndef SYSTEM_H
#define SYSTEM_H

#include <model.h>
#include <bootstrap.h>
#include <assert.h>
#include <stdio.h>

#include <debug.h>

#include <system/appcall.h>
#include <system/dircall.h>
#include <system/env.h>
#include <system/iassign.h>
#include <system/icall.h>
#include <system/icapture.h>
#include <system/iconst.h>
#include <system/ilist.h>
#include <system/iscoped.h>
#include <system/ivar.h>

// Starting an evaluation thread.
extern object inline transfer(context_object context);

// Structures to build interfaces to C.
extern void inline native();

// Meta-interpretation primitives.
extern void inline set_transfer(context_object context);
extern context_object inline get_context();

extern void inline new_target(context_object context, object target);

// Convenience macros.
#define return_value(rc)\
    argument_at(rc, 1)

#define make_eval_context(name, todo, env)\
    name = make_context((object)todo, 2);\
    set_message(name, EVAL);\
    set_argument(name, 1, (object)env);

#define eval_in_scope(input, env, output)\
    { \
        context_object make_eval_context(ci, input, env);\
        output = transfer(ci);\
    }


#define if_selector(selector, symb, todo)\
    if (selector.pointer == symb.pointer)\
        return todo();

// Bootstrapping natives.
extern void pre_eval_env();

// Convenience function for composing primitives into closures.
extern void doesnotunderstand(const char* class, object selector);

#endif
