
#define CHARACTER_TEST_SETUP \
Type_Character chr = new_Character(L'a'); \
Object result;

/* ========================================================================== */

void test_Character_asSmallint()
{
    CHARACTER_TEST_SETUP;
    result = EvalSend0((Object)chr,SMB_asSmallInt);
    ASSERT_TYPE(result, SmallInt_Class);
}


void test_Character_asSymbol()
{
    CHARACTER_TEST_SETUP;
    result = EvalSend0((Object)chr,SMB_asSymbol);
    ASSERT_TYPE(result, Symbol_Class);
    assert(((Type_String)result)->value[0] == chr->value);
}

void test_Character_asString()
{
    CHARACTER_TEST_SETUP;
    result = EvalSend0((Object)chr,SMB_asString);
    ASSERT_TYPE(result, String_Class);
    assert(((Type_String)result)->value[0] == chr->value);
}


/* ========================================================================== */

void test_Character()
{
    test_Character_asSmallint();
    test_Character_asSymbol();
    test_Character_asString();
}