#include <pinocchio.h>
#include <bootstrap.h>
#include <locale.h>
#include <string.h>

Object start_send(void** code, Object receiver)
{
    return method_context( code, receiver );
}

void pinocchio()
{
    RawArray code;

    code = new_RawArray(2, lookup_native(new_NativeName( L"SmallInteger", L"smaller")), 0);
    new_MethodClosure((Behavior)SmallInteger_class, new_Symbol(L"<"), code);

    code = new_RawArray(2, lookup_native(new_NativeName( L"SmallInteger", L"minus")), 0);
    new_MethodClosure((Behavior)SmallInteger_class, new_Symbol(L"-"), code);

    code = new_RawArray(2, lookup_native(new_NativeName( L"SmallInteger", L"plus")), 0);
    new_MethodClosure((Behavior)SmallInteger_class, new_Symbol(L"+"), code);

    code = new_RawArray(55,
            &method_context, U(2),
            OP(load_constant), new_SmallInteger(2), U(0), 
            OP(self_send), U(0), U(0), new_Symbol(L"<"), 
            OP(iftrue_iffalse), U(5), U(0),
            OP(return_constant), new_SmallInteger(1),
            
            OP(load_constant), new_SmallInteger(2), U(0), 
            OP(self_send), U(0), U(0), new_Symbol(L"-"),
            OP(result_send), U(0), U(0), new_Symbol(L"fib"),
            OP(store_result), U(1),

            OP(load_constant), new_SmallInteger(1), U(0),
            OP(self_send), U(0), U(0), new_Symbol(L"-"),
            OP(result_send), U(0), U(0), new_Symbol(L"fib"),

            OP(move), U(1), U(0),

            OP(result_send), U(0), U(0), new_Symbol(L"+"),
            OP(return_result) );


    new_MethodClosure((Behavior)SmallInteger_class, new_Symbol(L"fib"), code);

    SmallInteger integer = new_SmallInteger(34);

    SmallInteger result = (SmallInteger)start_send(code->data, (Object)integer);
    printf("Result: %li\n", result->value);
}

Array get_args(int argc, const char ** argv)
{
    Array args = new_Array(argc - 1);
    int i;
    argv++;
    for (i = 1; i < argc; i++) {
        const char * arg = *argv++;
        int length = strlen(arg);
        String sarg = raw_String(length);
        assert1(
            mbstowcs(sarg->character, arg, length) != -1,
            "failed to parse arguments");
        args->value[i-1] = (Object)sarg;
    }
    return args;
}

#ifndef UNIT_TESTING

int main(int argc, const char ** argv)
{
    setlocale(LC_ALL, "");
    pinocchio_bootstrap();

    //Array args = get_args(argc, argv);
    pinocchio();
    return EXIT_SUCCESS;
}

#endif
