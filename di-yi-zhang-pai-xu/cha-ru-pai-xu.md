# 直接插入排序

{% file src="../.gitbook/assets/insertion.c" caption="insertion.c" %}

{% code-tabs %}
{% code-tabs-item title="insertion.c" %}
```c
#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h>

// #define MAXN 100

void insertion(int arr[], int n)
{
    for (int j = 1; j < n; j++) {
        int key = arr[j];

        int i = j - 1;
        while (i >= 0 && key < arr[i]) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

int main()
{
    int arr[MAXN];

    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion(arr, MAXN);
     
    for (int i = 0; i < MAXN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

用命令`gcc insertion.c -D MAXN=100` 编译，其中100表示数组大小，可以换成其他数字。

