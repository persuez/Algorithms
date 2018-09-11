# 归并排序

{% file src="../.gitbook/assets/merge.c" caption="merge.c" %}

{% code-tabs %}
{% code-tabs-item title="merge.c" %}
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int arr[MAXN];

void merge(int arr[], int p, int q, int r);

void mergeSort(int arr[], int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    L[n1] = R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i = i + 1;
        } else {
            arr[k] = R[j];
            j = j + 1;
        }
    }
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % 1000000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, MAXN - 1);

    for (int j = 0; j < MAXN; j++)
        printf("%d ", arr[j]);
    printf("\n");

    return 0;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

用命令`gcc merge.c -D MAXN=1000000` 编译，其中1000000表示数组大小，可以换成其他数字。这里数组Ｌ和Ｒ的创建用到C99的特性。这里的代码不支持MAXN的值太大，因为Ｌ和Ｒ是局部变量，太大可能会栈满溢出。

