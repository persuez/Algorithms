# 随机快速排序

{% file src="../.gitbook/assets/quicksort.c" caption="quicksort.c" %}

{% code-tabs %}
{% code-tabs-item title="quicksort.c" %}
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[MAXN];

void
swap(int *val1, int *val2);

inline int
myrandom(int p, int r);

int
partition(int arr[], int p, int r);

int
random_partition(int arr[], int p, int r);

void
random_quicksort(int arr[], int p, int r)
{
    if (p < r) {
        int q = random_partition(arr, p, r);
        random_quicksort(arr, p, q - 1);
        random_quicksort(arr, q + 1, r);
    }
}

int
partition(int arr[], int p, int r)
{
    int pivot = arr[r];
    int i = p - 1, j = p;

    for (j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

int
random_partition(int arr[], int p, int r)
{
    int i = myrandom(p, r);
    swap(&arr[i], &arr[r]);
    return partition(arr, p, r);
}

void
swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int
myrandom(int p, int r)
{
    srand(time(NULL));
    return rand() % (r - p + 1) + p;
}

int
main()
{
    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % 10000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    random_quicksort(arr, 0, MAXN - 1);
    
    for (int j = 0; j < MAXN; j++) {
        printf("%d ", arr[j]);
    } 
    printf("\n");

    return 0;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}



