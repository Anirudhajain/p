#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <system/ast/Method.h>

/* ========================================================================= */

Method new_Method(uns_int paramCount,
                  uns_int localCount,
                  uns_int statementCount)
{
    NEW_ARRAY_OBJECT(Method, Optr[statementCount]);
    result->params = new_Array_raw(paramCount);
    result->locals = new_Array_raw(localCount);
    init_raw_variable_array(result->params, 0, paramCount, 0);
    init_raw_variable_array(result->locals, 0, localCount, paramCount);
    result->info   = empty_Info;
    result->size   = statementCount;
    result->package = nil;
    result->code = (Array)nil;
    return result;
}

Method new_Method_withAll(uns_int paramCount,
                          uns_int localCount,
                          uns_int statementCount, ...)
{
    Method result = new_Method(paramCount, localCount, statementCount);
    COPY_ARGS(statementCount, result->body);
    return result;
}

Method new_Method_with(Array params,
                       Array locals,
                       Array annotations,
					   Array threaded,
                       uns_int statementCount, ...)
{
    NEW_ARRAY_OBJECT(Method, Optr[statementCount]);
    result->params = params;
    result->locals = locals;
    result->annotations = annotations;
    init_variable_array(result->params, 0);
    init_variable_array(result->locals, result->params->size);
    result->info    = empty_Info;
    result->size    = statementCount;
    result->package = nil;
    result->code    = threaded;
    COPY_ARGS(statementCount, result->body);

    return result;
}

/* ========================================================================= */
