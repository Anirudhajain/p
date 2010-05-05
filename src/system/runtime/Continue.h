#ifndef CONTINUE_H
#define CONTINUE_H

#include <pinocchio.h>

/* ========================================================================= */

#define RUNTIME_CONTINUE_SIZE 4
#define RUNTIME_CONTINUE_VARS L"expOffset", L"cntOffset", L"interpreterStack", L"context"  

struct Runtime_Continue_t {
    uns_int     exp_offset;
    uns_int     cnt_offset;
    Object      iss;
    Object      env;
};

CREATE_INITIALIZERS(Runtime_Continue)
extern Runtime_Continue new_Runtime_Continue();
extern Runtime_Continue new_Runtime_Continue_offset(int offset);
extern void Runtime_Continue_escape(Runtime_Continue cont, Object return_value);
/* ========================================================================= */

#endif // CONTINUE_H
