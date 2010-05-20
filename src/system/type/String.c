#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <system/type/Symbol.h>
#include <system/type/String.h>

/* ========================================================================= */

DECLARE_CLASS(Type_String);
Type_String empty_Type_String;

/* ========================================================================= */

Type_String new_Type_String(const wchar_t * str)
{
    Type_String string = (Type_String)new_Type_Symbol(str);
    HEADER(string)     = Type_String_Class;
    return string;
}

Type_String new_Type_String_sized(uns_int size)
{
    Type_String result = NEW_ARRAYED(struct Type_Symbol_t, wchar_t[size]);
    HEADER(result)     = Type_String_Class;
    result->size       = size;
    while(size--) {
        result->value[size] = '\0';
    }
    result->hash       = Type_Symbol_hash((Type_Symbol)result);
    return result;
}

void pre_init_Type_String()
{
    Type_String_Class = new_Class(Type_Object_Class);
    Type_String_Class->layout = create_layout(0, WORDS);
    empty_Type_String = new_Type_String(L"");
}

/* ========================================================================= */

Type_String new_Type_String_from_charp(const char * input)
{
    int size          = strlen(input)+1;
    wchar_t cp[size];
    cp[size - 1]      = L'\0';
    wchar_t * copy    = &cp[0];
    swprintf(copy, size, L"%s", input);
    return new_Type_String(copy);
}

Type_String Type_String_concat_(Type_String str1, Type_String str2)
{
    assert1(str1 && str1->value, "Invalid Argument for String concat:");
    assert1(str2 && str2->value, "Invalid Argument for String concat:");
    int len = str1->size + str2->size + 1;
    wchar_t conc[len];
    conc[len - 1] = L'\0';
    wchar_t * concatenated = &conc[0];
    concatenated = wcsncpy(concatenated, str1->value, str1->size);
    assert0(concatenated!=NULL);
    wchar_t * rc = wcsncpy(concatenated + str1->size, str2->value, str2->size);
    assert0(rc!=NULL);
    return new_Type_String(concatenated);
}

int Words_compare(Type_Symbol s1, Type_Symbol s2)
{
    if (s1->size != s2->size) {
        return 0;
    }
    return !wcsncmp(s1->value, s2->value, s1->size);
}

CNT(Type_String_concat_)
    Object string = pop_EXP();
    Object self   = peek_EXP(0);
    poke_EXP(0, Type_String_concat_((Type_String)self, (Type_String)string));
}

NATIVE1(Type_String_concat_)
    Object w_arg = NATIVE_ARG(0);
    push_CNT(Type_String_concat_);
    RETURN_FROM_NATIVE(self); 
    Type_Class_direct_dispatch(w_arg, HEADER(w_arg), (Object)SMB_asString, 0);
}

NATIVE0(Type_String_asSymbol)
    RETURN_FROM_NATIVE(new_Type_Symbol_cached(((Type_String)self)->value));
}

// TODO check types not classes!
NATIVE2(Type_String_at_put_)
    Object w_arg0 = NATIVE_ARG(0);
    Object w_arg1 = NATIVE_ARG(1);
    ASSERT_INSTANCE_OF(w_arg0, Number_SmallInt_Class);
    ASSERT_INSTANCE_OF(w_arg1, Type_Character_Class);
    int index = unwrap_int(w_arg0) - 1;
    assert(0 <= index, printf("Index below 0: %i\n", index));
    assert(index < ((Type_String)self)->size,
        printf("%i is out of Bounds[%"F_I"u] %p\n",
                    index,
                    ((Type_String)self)->size,
                    self));
    ((Type_String)self)->value[index] = ((Type_Character)w_arg1)->value;
    ((Type_String)self)->hash         = Type_Symbol_hash((Type_Symbol)self);
    RETURN_FROM_NATIVE(self);
}

NATIVE1(Type_String_basicNew_)
    // TODO check type
    Object w_size      = NATIVE_ARG(0);
    int size           = unwrap_int(w_size);
    Type_String result = new_Type_String_sized(size);
    RETURN_FROM_NATIVE(result);
}

int wchar_withbase_to_number(uns_int base, const wchar_t * string, uns_int size)
{
    // TODO handle overflows!
    int result = 0;
    int sign;

    if (*string == L'-') {
        sign = -1;
        string++;
    } else {
        sign = 1;
    }

    while (size--) {
        uns_int chr = *string++ - 48;
        // ensure it's within the 0-9 range
        if (chr < 10) {
            if (chr < base) {
                result = (result * base) + chr;
                continue;
            }
            break;
        }
        // shift from 0-9 to A-Z
        chr = chr + 48 - 65 + 10;
        if (chr < base) {
            result = (result * base) + chr;
            continue;
        }
        break;
    }

    return sign * result;
}

Object wchar_to_number(const wchar_t * string, uns_int size)
{
    // TODO make it accept other types ... or just use Pharo's version.
    // TODO handle overflows!
    // TODO handle floats!

    int result = 0;
    int sign;

    if (*string == L'-') {
        sign = -1;
        string++;
    } else {
        sign = 1;
    }

    while (size--) {
        uns_int chr = *string++ - 48;
        if (chr < 10) {
            result = (result * 10) + chr;
            continue;
        }
        if (chr == L'r' - 48) {
            assert0(result <= 36);
            result = wchar_withbase_to_number(result, string, size);
        }
        break;
    }
    return (Object)new_Number_SmallInt(sign * result);
}

char * unicode_to_ascii(const wchar_t* str)
{
    int len        = wcslen(str);
    char* charname = (char*)PALLOC(sizeof(char[len]));
    assert1(wcstombs(charname, str, len) == len, "String not ASCII compatible.");
    return charname;
}

wchar_t * ascii_to_unicode(const char* str)
{
    int len           = strlen(str);
    wchar_t* charname = (wchar_t*)PALLOC(sizeof(wchar_t[len]));
    assert1(mbstowcs(charname, str, len) == len, "String not UTF compatible.");
    return charname;
}

NATIVE0(Type_String_asNumber)
    Type_Symbol symbol = (Type_Symbol)self;
    RETURN_FROM_NATIVE(wchar_to_number(symbol->value, symbol->size));
}

/* ========================================================================= */

void post_init_Type_String()
{
    REFER_TO(Type_String);
    Collection_Dictionary natives = add_plugin(L"Type.String");
    store_native(natives, SMB__concat,   NM_Type_String_concat_);
    store_native(natives, SMB_asSymbol,  NM_Type_String_asSymbol);
    store_native(natives, SMB_at_put_,   NM_Type_String_at_put_);
    store_native(natives, SMB_asNumber,  NM_Type_String_asNumber);
    store_native(natives, SMB_basicNew_, NM_Type_String_basicNew_);
}

