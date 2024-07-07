#ifndef _PDQSORT_H
#define _PDQSORT_H

typedef void (*swap_func_t)(void *a, void *b, int size);
typedef int (*cmp_r_func_t)(const void *a, const void *b, const void *priv);
typedef int (*cmp_func_t)(const void *a, const void *b);

size_t pdqsort(void *base, size_t num, size_t size, cmp_func_t cmp_func, swap_func_t swap_func);

#endif
