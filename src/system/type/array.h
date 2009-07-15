#ifndef SYSTEM_ARRAY_H
#define SYSTEM_ARRAY_H

#include <system/type/type.h>
export_type(array);

#define array_check_bounds(array, index)\
	error_guard(0 <= index, L"Out of bounds");\
	error_guard(index < array_size(array), L"Out of bounds");

extern array_object             make_array(int size);

extern int              inline array_size(array_object array);
extern object           inline array_at(array_object array, int index);
extern object           inline raw_array_at(array_object array, int index);
extern void             inline array_at_put(array_object array,
                                            int index, object new_value);
extern void             inline raw_array_at_put(array_object array,
                                                int index, object new_value);

struct array {
    int                 size;
    object              values[];
};

#endif // SYSTEM_ARRAY_H