#include <system.h>
#include <scheme/symbols.h>

// Global symbols, readable format
// General purpose
object EVAL;
object PRE_EVAL_ENV;
// Variable
object ASSIGN_IN;
object FETCH_FROM;
// Environment
object PARENT;
object SCOPE_KEY;
object SET_PARENT;
object STORE_AT_IN;
object SUBSCOPE_KEY;
// Iscope_class
object NEW_SIZE;
// Iscope
object IAPPLY;
object APPLY_IN;
object SCOPE;
object SHIFT;
// Icapture
object INSTANCE;
// Iassign
object TO_EXPRESSION;
// Icall
object TO_SIZED;
// Ifixed
object DELEGATE;
object DISPATCH_DELEGATE_SIZE;
object NEW;
object OBJECT_AT;
object OBJECT_AT_PUT;
object SET_DISPATCH_DELEGATE;
object SIZE;
object SIZED;
object WITH_SIZE;
// File
object END;
object ON;
object READ;
object READ_ALL;
object WRITE;

void bootstrap_scheme_symbols() {
    // Ensure all symbols used by the VM are bootstrapped.
    define_symbol(APPLY_IN,                 L"apply:in:");
    define_symbol(DELEGATE,                 L"delegate");
    define_symbol(DISPATCH_DELEGATE_SIZE,   L"dispatch:delegate:size:");
    define_symbol(END,                      L"atEnd");
    define_symbol(EVAL,                     L"eval");
    define_symbol(IAPPLY,                   L"iapply:");
    define_symbol(INSTANCE,                 L"instance");
    define_symbol(NEW,                      L"basicNew");
    define_symbol(NEW_SIZE,                 L"new:size:");
    define_symbol(OBJECT_AT,                L"objectAt:");
    define_symbol(OBJECT_AT_PUT,            L"objectAt:put:");
    define_symbol(ON,                       L"on:");
    define_symbol(PARENT,                   L"parent");
    define_symbol(PRE_EVAL_ENV,             L"eval:");
    define_symbol(READ,                     L"readChar");
    define_symbol(READ_ALL,                 L"readAllChars")
    define_symbol(SCOPE,                    L"scope");
    define_symbol(SCOPE_KEY,                L"scope:key:");
    define_symbol(SET_DISPATCH_DELEGATE,    L"dispatch:delegate:");
    define_symbol(SET_PARENT,               L"parent:");
    define_symbol(SHIFT,                    L"shift");
    define_symbol(SIZE,                     L"size");
    define_symbol(SIZED,                    L"basicNew:");
    define_symbol(STORE_AT_IN,              L"store:at:in:");
    define_symbol(SUBSCOPE_KEY,             L"subScope:key:");
    define_symbol(TO_EXPRESSION,            L"to:expression:");
    define_symbol(TO_SIZED,                 L"to:sized:");
    define_symbol(WITH_SIZE,                L"size:");
    define_symbol(WRITE,                    L"writeChar:");
}
