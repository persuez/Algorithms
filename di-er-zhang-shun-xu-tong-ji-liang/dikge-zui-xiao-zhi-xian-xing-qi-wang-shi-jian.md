# 第k个最小值（线性期望时间）

{% file src="../.gitbook/assets/selection\_partition.c" caption="selection\_partition.c" %}

{% code-tabs %}
{% code-tabs-item title="selection\_partition.c" %}
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int arr[MAXN];

void
swap(int *val1, int *val2);

inline int
myrandom(int p, int r);

int
partition(int arr[], int p, int r);

int
random_partition(int arr[], int p, int r);

int
random_selection(int arr[], int p, int r, int k)
{
    assert(p <= r);
    // p > r => 可能是arr的大小为０（和输入有关），或可能是k的值比数组大小还大
    int q = random_partition(arr, p, r);
    int kth = q - p + 1;
    // 以q为下标的数是[p, r]数组中第q - p + 1小的数, 
    // 即kth是从p到q的距离，也就是p到q之间（包含p和q）的元素个数
    if (k == kth)
        return arr[q];
    else if (kth < k)
        return random_selection(arr, q + 1, r, k - kth);
    else
        return random_selection(arr, p, q - 1, k);
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

    int kth = random_selection(arr, 0, MAXN - 1, 5);

    printf("%d \n", kth);

    return 0;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

