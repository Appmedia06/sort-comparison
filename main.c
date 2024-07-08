#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "queue.h"
#include "list_sort.h"
#include "timsort.h"
#include "pdqsort.h"

#define MAX_LEN 1000

static int cmp(void *priv,
               const struct list_head *list1,
               const struct list_head *list2)
{
    return strcmp(list_entry(list1, element_t, list)->value,
                  list_entry(list2, element_t, list)->value);
}

static int cmpuint64(const void *a, const void *b)
{
    return *(uint64_t *)a < *(uint64_t *)b;
}

void rand_generate_list(struct list_head *head, size_t size, size_t rand_size)
{
    srand(time(NULL));
    size_t tmp = 0;
    char *str = malloc(70 * sizeof(char));
    for (size_t i = 0; i < size; i++) {
        tmp = (i >= rand_size) ? i : (size_t)rand();
        sprintf(str, "%ld", tmp);
        q_insert_tail(head, str);
    }
}

void rand_generate_arr(uint64_t *arr, size_t size, size_t rand_size)
{
    size_t tmp;
    for (size_t i = 0; i < size; ++i) {
        tmp = (i >= rand_size) ? i : (size_t)rand();
        arr[i] = tmp;
    }
}


int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("usage: main <sort type> <size> <rand size>\n");
        return -1;
    }

    size_t sort_type = 0;
    if (!sscanf(argv[1], "%ld", &sort_type)) {
        printf("Invaild sort type %s\n", argv[1]);
        return -3;
    }

    size_t size = 0;
    if (!sscanf(argv[2], "%ld", &size)) {
        printf("Invaild size %s\n", argv[2]);
        return -3;
    }

    size_t rand_size = 0;
    if (!sscanf(argv[3], "%ld", &rand_size)) {
        printf("Invaild rand_size %s\n", argv[3]);
        return -3;
    }


    size_t comparison_count = 0;
    struct timespec start, end;

    if (sort_type == 0) {
        struct list_head *head = q_new();
        rand_generate_list(head, size, rand_size);
        clock_gettime(CLOCK_MONOTONIC, &start);
        comparison_count = list_sort(NULL, head, cmp);
        clock_gettime(CLOCK_MONOTONIC, &end);
        q_free(head);
    }
    else if (sort_type == 1) {
        struct list_head *head = q_new();
        rand_generate_list(head, size, rand_size);
        clock_gettime(CLOCK_MONOTONIC, &start);
        comparison_count = timsort(NULL, head, cmp);
        clock_gettime(CLOCK_MONOTONIC, &end);
        q_free(head);
    }
    else if (sort_type == 2) {
        uint64_t *arr = malloc(sizeof(uint64_t) * size);
        rand_generate_arr(arr, size, rand_size);
        clock_gettime(CLOCK_MONOTONIC, &start);
        comparison_count = pdqsort(arr, size, sizeof(uint64_t), cmpuint64, NULL);
        clock_gettime(CLOCK_MONOTONIC, &end);
        free(arr);
    }
    else {
        printf("Invaild sort type: \n0: list_sort\n1: timsort\n2: pdqsort\n");
        return 0;
    }

    // show_queue(head, 10); // for debug
    printf("comparison count = %lu\n", comparison_count);

    double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;
    printf("Sorting execution time: %f seconds\n", time_spent);

    return 0;
}
