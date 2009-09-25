
void test_SmallInt_equals_()
{
    Object int0     = (Object)new_SmallInt(0);
    Object int2     = (Object)new_SmallInt(2);
    Object result;
    
    result = EvalSend1(int0, SMB_equals_, int2);
    assert(result == (Object)False);
    result = EvalSend1(int2, SMB_equals_, int0);
    assert(result == (Object)False);
    
    result = EvalSend1(int0, SMB_equals_, int0);
    assert(result == (Object)True);
    
    result = EvalSend1(int2, SMB_equals_, int2);
    assert(result == (Object)True);
}

#define SMALLINT_BINOP_TEST(name, op) \
void test_SmallInt_##name##_() \
{ \
    Type_SmallInt int4 = new_SmallInt(4); \
    Type_SmallInt int8 = new_SmallInt(8); \
    Object result; \
    result = EvalSend1((Object)int4, SMB_##name##_, (Object)int8); \
    ASSERT_TYPE(result, SmallInt_Class); \
    printf("%i\n", ((Type_SmallInt)result)->value); \
    assert(((Type_SmallInt)result)->value == (int4->value op int8->value)); \


SMALLINT_BINOP_TEST(plus,       +)
}

SMALLINT_BINOP_TEST(minus,      -)
}

SMALLINT_BINOP_TEST(times,      *)
}

SMALLINT_BINOP_TEST(divide,     /)
}

SMALLINT_BINOP_TEST(shiftRight, >>)
}

SMALLINT_BINOP_TEST(shiftLeft,  <<)
}

/* ======================================================================== */

void test_SmallInt()
{
    test_SmallInt_equals_();
    test_SmallInt_plus_();
    test_SmallInt_minus_();
    test_SmallInt_divide_();
    test_SmallInt_times_();
    test_SmallInt_shiftLeft_();
    test_SmallInt_shiftRight_();
}