
#include <stdlib.h>
#include <stdio.h>
#include <system/io/File.h>

/* ======================================================================== */

Type_Class File_Class;

/* ======================================================================== */

Type_File StandardIn;
Type_File StandardOut;
Type_File NilStream;

Type_File 
new_File()
{
    // TODO implement
    return NULL;
}

Type_File 
new_File_FromPath(wchar_t * path)
{
    // TODO implement
    return NULL;
}

extern void pre_initialize_File()
{
    File_Class = new_Named_Class((Object)Object_Class, L"File");
}

/* =========================================================================*/


/* =========================================================================*/

extern void post_initialize_File()
{
    // TODO install methods 
}