# 第k个最小值（线性最坏时间）

对于这个算法，如果输入有大量相同值时，中位数的中位数的位置不好求。把数组划分为三部分：小于主元，等于主元，大于主元。同时在划分时求出等于主元部分的元素数量，记主元的最低位置为i,最高位置为j，那么如果k在\[i, j\]中，就直接返回j,否则递归求解。实现中用在数组中等于主元的元素的数量来实现上述想法。这个算法的主要想法是得到一个确实好的pivot,而不仅仅只是那么好的主元。而STL的nth\_element是通过一种称为“三点中值”的方法来得到一个好的主元，“三点中值”即选取头部，中间，尾部三个值的中位数作为主元。

{% file src="../.gitbook/assets/selection \(1\).c" caption="selection.c" %}

{% code-tabs %}
{% code-tabs-item title="selection.c" %}
```c
//#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void
swap(int *val1, int *val2);

void
insertionsort(int arr[], int p, int r);

void
find_median(int arr[], int p, int r);

int
partition(int arr[], int p, int r, int pivot, int *pivotNum);

// 返回第k小的数在数组arr中的最终索引（因为arr数组在中间过程会被重新排列）
int
kthselect(int arr[], int p, int r, int k)
{
    int n = r - p + 1;
    if (n < 140) {
        insertionsort(arr, p, r);
        return p + k - 1;
    }
    // 将数组分成ceil(n / 5)个组，并找出这些组的中位数，
    // 实现中将这些中位数放到数组的前面，以便于递归查找中位数的中位数
    find_median(arr, p, r);
    // 递归查找中位数的中位数，返回它的位置（因为可以比较方便的结合下面的pivotNum处理有
    // 相同元素的情况
    int pivotIndex = kthselect(arr, p, ceil(n  * 1.0 / 5) - 1, (ceil(n * 1.0 / 5) - 1 + p) / 2);
    // 以中位数的中位数为主元进行划分，划分函数返回主元的位置（如果有重复的主元，返回最后的位置），
    // 并且通过指针传参，带回相同主元的数量，实现中用pivotNum表示，为在有大量重复元素的环境下保证时间复杂度
    // 这里的划分函数partition和算导中快排的实现方式不一样，是为了方便获得pivotNum
    // (其实是为了得到从开始位置到最低的主元的位置的距离(包括端点），实现中记为lowNum)
    int pivotNum = 0, pivot = arr[pivotIndex];
    int pivotEndIndex = partition(arr, p, r, pivot, &pivotNum);
    // 把数组划分为三部分：小于划分元素的，等于划分元素的，大于划分元素的
    // 所以如果k在“等于划分元素的“这部分，就直接返回最后的位置（pivotEndIndex)
    // 如果k在”小于划分元素的“这部分，就在这部分递归调用kthselect查找第k个元素 
    // 如果k在”大于划分元素的“这部分，就在这部分递归调用kthselect查找第k - #小于等于pivotNum(实现中记为highNum)
    int highNum = pivotEndIndex - p + 1;
    int lowNum = highNum - pivotNum + 1;
    if (k >= lowNum && k <= highNum)
        return pivotEndIndex;
    else if (k < lowNum)
        return kthselect(arr, p, pivotEndIndex - pivotNum, k);
    else
        return kthselect(arr, pivotEndIndex + 1, r, k - highNum);
}

void
swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void
insertionsort(int arr[], int p, int r)
{
    for (int i = p + 1; i <= r; i++) {
        int key = arr[i], j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void
find_median(int arr[], int p, int r)
{
    int n = r - p + 1, j = p;
    for (int i = p; i < n; i = i + 5) {
        insertionsort(arr, i, i +4);
        swap(&arr[i + 2], &arr[j]);
        j = j + 1;
    }
    // 如果有不完整的组
    if (n % 5 != 0) {
        int begin = p + n / 5 * 5;
        insertionsort(arr, begin, r);
        swap(&arr[(begin + r) / 2], &arr[j]);
    }
}

int
partition(int arr[], int p, int r, int pivot, int *pivotNum)
{
    // 先通过快排的partition将数组划分为两部分(<=和>)
    // 最终指示器i将停留在最后一个小于或等于pivot的元素上
    int i = p - 1;
    for (int k = p; k <= r; k++) {
        if (arr[k] <= pivot) {
            i = i + 1;
            swap(&arr[k], &arr[i]);
        }
    }

    // 然后通过快排的partition将<=那部分再划分为两部分(<和=)
    // 最终指示器j将停留在最火一个小于pivot的元素上
    int j = p - 1;
    for (int k = p; k <= i; k++) {
        if (arr[k] < pivot) {
            j = j + 1;
            swap(&arr[k], &arr[j]);
        }
    }

    *pivotNum = i - j;
    return i;
}

int
main()
{
    int arr[MAXN];
    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    int index = kthselect(arr, 0, MAXN - 1, 12);
    int res = arr[index];
    printf("%d\n", res);

    // 测试正确性，运行是通过的
    int cmp(const void *a, const void *b)
    {
        return *(int *)a - *(int *)b;
    }
    qsort(arr, MAXN, sizeof(int), cmp);
    if (res != arr[11])
        printf("error\n");

    return 0;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

