#ifndef ARRAY_H
#define ARRAY_H

#include <pinocchio.h>

/* ========================================================================= */

struct Array_t {
    uns_int size;
    Optr  values[];
};

extern Array empty_Array;

CREATE_INITIALIZERS(Array)

extern Array new_Array_raw(uns_int c);
extern Array new_Array(uns_int c, Optr v[]);
extern Array new_Array_with(uns_int c, ...);
extern Array new_Array_withAll(uns_int c, Optr element);
extern Optr raw_Array_at(Array array, Optr tag, int index);
extern void raw_Array_at_put(Array array, Optr tag,
                                  int index, Optr value);
extern Optr raw_Array_instAt(Array array, Optr tag, int index);
extern void raw_Array_instAt_put(Array array, Optr tag,
                                      int index, Optr value);
/* ========================================================================= */

#endif // ARRAY_H
