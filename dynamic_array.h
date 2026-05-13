#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

/* typedef struct { */
/*     int *items; */
/*     size_t count; */
/*     size_t capacity; */
/* } DA; */

#define DA_INIT_CAPACITY 256

#define da_reserve(da, expected_capacity)				\
    do{									\
	if (expected_capacity > da.capacity) {				\
	    if (da.capacity == 0) {					\
		da.capacity = DA_INIT_CAPACITY;					\
	    }								\
	    while (expected_capacity > da.capacity) {			\
		da.capacity *= 2;					\
	    }								\
	    da.items = realloc(da.items, da.capacity * sizeof(*da.items)); \
	}								\
    } while (0)								\
	
#define da_append(da, item)			\
    do {					\
	da_reserve(da, da.count + 1);		\
	da.items[da.count++] = item;		\
    } while (0)					\

#define da_free(da) free(da.items)

#define da_resize(da, new_size)			\
    do {					\
	da_reserve(da, new_size);		\
	da.count = (new_size);			\
    } while(0)					\

#define da_pop(da) da.items[--da.count]

#define da_first(da) da.items[0]

#define da_last(da) da.items[da.count - 1]

#define da_remove_unordered(da, i)		\
    do {					\
	size_t j = i;				\
	da.items[j] = da.items[--da.count];	\
    } while (0)					\

#endif // DYNAMIC_ARRAY_H
