#ifndef NATIVEMETHOD_H
#define NATIVEMETHOD_H

#include <stdlib.h>
#include <stdio.h>
#include <pinocchio.h>

/* ========================================================================= */

struct AST_NativeMethod_t {
    uns_int         size;
    AST_Info        info;
    Collection_Array      params;
    Collection_Array      locals;
    Object          package;
    Collection_Array      annotations;
    native          code;
    Object          body[];
};

CREATE_INITIALIZERS(AST_NativeMethod)

extern AST_NativeMethod new_AST_NativeMethod_with(Collection_Array params,
                                      Collection_Array locals,
                                      Collection_Array annotations,
                                      uns_int statementCount, ...);

/* ========================================================================= */

#define NATIVE(name)\
static void NM_##name(Object self, Type_Class class, uns_int argc) {
#define NATIVE0(name)  NATIVE(name) ASSERT_ARG_SIZE(0);
#define NATIVE1(name)  NATIVE(name) ASSERT_ARG_SIZE(1);
#define NATIVE2(name)  NATIVE(name) ASSERT_ARG_SIZE(2);
#define NATIVE3(name)  NATIVE(name) ASSERT_ARG_SIZE(3);
#define NATIVE4(name)  NATIVE(name) ASSERT_ARG_SIZE(4);

#define RETURN_FROM_NATIVE(exp)\
    zapn_EXP(argc + 1);\
    poke_EXP(0, exp);

#define NATIVE_ARG(idx) peek_EXP(argc - idx - 1)

#define SELF ((Type_Object) self)
/* ========================================================================= */

extern void AST_NativeMethod_invoke(Runtime_MethodClosure closure, Object self,
                                    Type_Class class, uns_int argc);
extern native lookup_native(Object primitive_name, Object module_name);

/* ========================================================================= */

#endif // NATIVEMETHOD_H
