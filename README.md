# Sort comparison
Discuss the average number of comparisons and execution time of Timsort, pdqsort, list_sort
## How to run
You can compile the `main` program using the following command
```
$ make
```
And you can run program like
```
$ ./main <sort type> <size> <rand size>
```
* `sort type`:
  * 0: `list_sort`
  * 1: `Timsort`
  * 2: `pdqsort`
* `size`: sequence length
* `rand size`: The number of random numbers in the sequence

## Files
### main program
* `main.c`: Test the number of comparisons and execution time of different sorting algorithms.
### Sort implementation
#### list sort
* `queue.[ch]`: Complete some queued operations.
* `list.h`: Linux-like doubly-linked list implementation.
* `list_sort.[ch]`: Implementation of list sort.
#### timsort
* `timsort.[ch]`: Implementation of timsort.
#### pdqsort
* `pdqsort.[ch]`: Implementation of pdqsort. Reference from [hankluo6/pdqsort](https://github.com/hankluo6/pdqsort)
#### compilation
* `Makefile`: Builds the experiment program `main`

### Experiment result
#### Sequence length 10000, completely random
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times)  | 121006    | 131788   | 165964   |
| Sorting time (sec) | 0.004242  | 0.004398 | 0.001908 |
    
#### Sequence length 50000, completely random
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times)  | 721306    | 770839   | 954597   |
| Sorting time (sec) | 0.011339  | 0.010800 | 0.009194 |

#### Sequence length 10000, half random
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times)  | 98943     | 75600    | 125043   |
| Sorting time (sec) | 0.002629  | 0.002530 | 0.001190 |
    
#### Sequence length 50000, half random
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times)  | 579353    | 451795   | 670515   |
| Sorting time (sec) | 0.007334  | 0.006555 | 0.006200 |
    
#### Sequence length 10000, sorted (ascending)
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times) | 73777     | 21070    | 20008    |
| Sorting time (sec) | 0.000972  | 0.000354 | 0.000103 |
    
#### Sequence length 50000, sorted (ascending)
|               | list_sort | Timsort  | pdqsort  |
| ------------- | --------- | -------- | -------- |
| Number of comparisons (times)  | 437120    | 105515   | 100008   |
| Sorting time (sec) | 0.003127  | 0.001418 | 0.000532 |

#### Visualization
* Number of comparisons, sequence length 50000
![compare](https://github.com/Appmedia06/sort-comparison/blob/main/img/compare.png)
* Sorting Time, sequence length 50000
![time](https://github.com/Appmedia06/sort-comparison/blob/main/img/time.png)

### Detailed analysis
[探討 Timsort, pdqsort、list_sort 平均比較次數](https://hackmd.io/BX0rbCCST7mxxYi0XmKprg?view#%E6%8E%A2%E8%A8%8E-Timsort-pdqsort%E3%80%81list_sort-%E5%B9%B3%E5%9D%87%E6%AF%94%E8%BC%83%E6%AC%A1%E6%95%B8)
