void test_ast_self()
{
    Type_SmallInt integer       = new_SmallInt(70);
    Type_SmallInt integer7      = new_SmallInt(7);
    AST_Constant integer7_const = new_Constant((Object)integer7);
    Type_Array body   = new_Array_With(3, (Object)integer7_const);
    body->values[2]     = Self;
    AST_Method method = new_Method(0, body);
    Type_Symbol test  = new_Symbol(L"test");
    store_method(SmallInt_Class, (Object)test, (Object)method);
    Object result = EvalSend((Object)integer, (Object)test, Empty_Array);
    assert(result == (Object)integer);
}


/* ======================================================================== */

void test_Self()
{
    LOG(" SELF TEST ---------------------------------------------------");
    test_ast_self();
}