
void test_Array_ObjectAt_()
{
    Object integer       = (Object)new_SmallInt(10);
    Object integer2      = (Object)new_SmallInt(2);
    Type_Array array   = new_Array_With(10, integer);
    Type_Array args    = new_Raw_Array(1);
    array->values[4]  = integer2;
    int i; 
    for (i=0; i<array->size->value; i++) {
        if (i==4) { continue; }
        args->values[0] = (Object)new_SmallInt(i); 
        assert(EvalSend((Object)array,SMB_objectAt_, args) == integer);
        assert(array->values[i] == integer);
    }
    args->values[0] = (Object)new_SmallInt(4); 
    assert(EvalSend((Object)array,SMB_objectAt_, args) == integer2);
}

void test_Array_size()
{
    Object integer     = (Object)new_SmallInt(10);
    Type_Array array = new_Array_With(10, integer);
    Object result      = EvalSend((Object)array,SMB_size, Empty_Array);
    assert(((Type_SmallInt) result)->value == 10);
    
    result = EvalSend(integer,SMB_equals_, new_Array_With(1, result));
    //printf("%ls\n", ((Type_String)((Type_Class)HEADER(result))->name)->value);
    assert( result == (Object)True);
}

void test_Array_ObjectAt_put()
{
    Object result;
    Object integer     = (Object)new_SmallInt(10);
    Object integer0    = (Object)new_SmallInt(0);
    Object integer1    = (Object)new_SmallInt(1);
    Object integer2    = (Object)new_SmallInt(2);
    Type_Array array = new_Array_With(10, integer);
    Type_Array args  = new_Array_With(2, (Object)integer1);
    args->values[0] = integer0; 
    
    result = EvalSend((Object)array,SMB_objectAt_put_, args);
    assert(result == integer1);
    assert(array->values[0] == integer1);
    
    args->values[0] = integer2; 
    args->values[1] = integer1;
    result = EvalSend((Object)array,SMB_objectAt_put_, args);
    assert(result == integer1);
    assert(array->values[2] == integer1);
}


/* ======================================================================== */

void test_Array() {
    test_Array_ObjectAt_();
    test_Array_size();
    test_Array_ObjectAt_put();
}