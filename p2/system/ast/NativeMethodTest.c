

int test_native_method_evaluation_testmethod_called;
void test_native_method_evaluation_testmethod(Object self, Object class, Type_Array args) {
    test_native_method_evaluation_testmethod_called++;
}

void test_ast_native_method_evaluation()
{
    test_native_method_evaluation_testmethod_called = 0;
    AST_Native_Method method = new_Native_Method(test_native_method_evaluation_testmethod);
    Object method_const        = (Object)new_Constant((Object)method);
    
    Object result = Eval((Object)new_Send(method_const,SMB_eval, new_Raw_Array(0)));
    printf("%ls\n", Object_classname(result));
    assert(result == (Object)method);
    assert(test_native_method_evaluation_testmethod_called == 1);
}


/* ======================================================================== */

void test_NativeMethod()
{
    test_ast_native_method_evaluation();
}