#include <pinocchio.h>

/* ======================================================================= */

NativesDictionary NATIVES;

/* ======================================================================= */

NativeName new_NativeName(const wchar_t * module, const wchar_t * name)
{
    NEW_OBJECT_WITH_CLASS(NativeName, NativeName_class );
    result->name = new_Symbol( name );
    result->module = new_Symbol( module );
    return result;
}

native lookup_native(NativeName name)
{
    return NativesDictionary_lookup(NATIVES, name);
}

void install_native(NativeName name, native aNative)
{
    NativesDictionary_store(NATIVES,name,aNative);
}

void init_natives() 
{
    NATIVES = new_NativesDictionary();
    install_natives_SmallInteger();    
}