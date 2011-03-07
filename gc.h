#ifndef GC_H
#define GC_H

/* ======================================================================= */

#ifndef NOGC
    #include <gc/gc.h>
    #ifdef GC_MALLOC
        #define PALLOC GC_MALLOC
    #endif // GC_MALLOC
#endif // NOGC

#ifndef PALLOC
    #define PALLOC malloc
#endif // PALLOC

#define NEW_STACK_OBJECT(type, cls, size)\
    cls result = (cls)thread->stack_pointer->data;\
    thread->stack_pointer->data += (sizeof(struct type) + sizeof(Object[size])) / 8;\
    result->header.class        = (Behavior)cls##_class;\
    result->size                = size;

#define INSTANTIATE(result, type, cls)\
    result = PALLOC(sizeof(struct type));\
    result->header.class = (Behavior)cls;

#define NEW_OBJECT_NAMED_WITH_CLASS(result, type, class)\
	type INSTANTIATE(result, type, class)

#define NEW_OBJECT_WITH_CLASS(type, class)\
    NEW_OBJECT_NAMED_WITH_CLASS(result, type, class)

#define NEW_OBJECT_NAMED(result, type)\
    NEW_OBJECT_NAMED_WITH_CLASS(result, type, type##_class)

#define NEW_OBJECT(class) NEW_OBJECT_NAMED(result, class)

#define INSTANTIATE_ARRAY(result, cls, arraytype, arraysize)\
    result = PALLOC(sizeof(struct cls) + sizeof(arraytype[arraysize]));\
    result->header.class    = (Behavior)cls##_class;\
    result->header.variable = 1;\
	result->size            = arraysize;

#define NEW_ARRAYED(class, arraytype, arraysize)\
	class INSTANTIATE_ARRAY(result, class, arraytype, arraysize)

/* ======================================================================= */

#endif // GC_H
