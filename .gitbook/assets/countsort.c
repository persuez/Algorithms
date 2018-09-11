#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int arr[MAXN];
int res[MAXN];

// 数组arr中的值在[0, MAXRANGE - 1]
#define MAXRANGE 10001

void
counting_sort(int arr[], int res[], int n, int range)
{
    int aux[range];
    memset(aux, 0, sizeof(aux));
    
    for (int i = 0; i < n; i++)
        aux[arr[i]]++;
    // now aux[i] = arr数组中i的数量
    for (int j = 1; j < range; j++)
        aux[j] = aux[j - 1] + aux[j];
    // now aux[i] = arr数组中小于或等于i的数量
    // 为保证为stable排序，所以k从n到0;
    // 如果k从0到k，则排序是正确的，但不是stable的（如果有重复元素）
    for (int k = n - 1; k >= 0; k--) {
        res[aux[arr[k]]] = arr[k];
        aux[arr[k]]--;
    }
}

int
main()
{
    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % MAXRANGE;
        printf("%d ", arr[i]);
    }
    printf("\n");

    counting_sort(arr, res, MAXN, MAXRANGE);

    for (int j = 0; j < MAXN; j++)
        printf("%d ", res[j]);
    printf("\n");

    return 0;
}
