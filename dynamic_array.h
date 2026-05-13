#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define da_reserve(da, expected_capacity)				\
    do{									\
	if (expected_capacity > da.capacity) {				\
	    if (da.capacity == 0) {					\
		da.capacity = 256;					\
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

/* typedef struct { */
/*     int *items; */
/*     size_t count; */
/*     size_t capacity; */
/* } Numbers; */

/* int main(void) */
/* { */
/*     Numbers da = { 0 }; */
/*     da_resize(da, 500); */
/*     da_reserve(da, 1000); */

/*     printf("da count: %zu\n", da.count); */
    
/*     for (int x = 0; x < 500; x++) { */
/* 	da.items[x] = x; */
/*     } */

/*     for (int x = 0; x < 500; x++) { */
/* 	da_append(da, x); */
/*     } */

/*     for (int x = 0; x < 500; x++) { */
/* 	int a = da_pop(da); */
/*     } */

/*     printf("da count: %zu\n", da.count); */
/*     printf("da capacity: %zu\n", da.capacity); */
    
/*     printf("da first: %d\n", da_first(da)); */
/*     printf("da last: %d\n", da_last(da)); */

/*     da_remove_unordered(da, 10); */
/*     printf("da first: %d\n", da_first(da)); */
/*     printf("da last: %d\n", da_last(da)); */
    
/*     for (size_t i = 0; i < da.count; i++) { */
/* 	printf("%d\n", da.items[i]); */
/*     } */

/*     da_free(da); */
/*     return 0; */
/* } */
#endif // DYNAMIC_ARRAY_H
