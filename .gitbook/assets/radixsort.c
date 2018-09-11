#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int arr[MAXN];
int res[MAXN];

// 数组arr中的值在[0, MAXRANGE)
#define MAXRANGE 10000

void
counting_sort(int arr[], int res[], int n, int d)
{
    int aux[10];
    memset(aux, 0, sizeof(aux));
    
    int digit = (int)pow(10.0, d - 1), _10digit = 10 * digit;
    for (int i = 0; i < n; i++) {
        aux[arr[i] % _10digit / digit]++;
    }
    // now aux[i] = arr数组中i的数量
    for (int j = 1; j < 10; j++)
        aux[j] = aux[j - 1] + aux[j];
    // now aux[i] = arr数组中小于或等于i的数量
    // 为保证为stable排序，所以k从n到0;
    // 如果k从0到k，则排序是正确的，但不是stable的（如果有重复元素）
    for (int k = n - 1; k >= 0; k--) {
        res[aux[arr[k] % _10digit / digit] - 1] = arr[k];
        aux[arr[k] % _10digit / digit]--;
    }
}

void
radixsort(int arr[], int res[], int n, int d)
{
    for (int i = 1; i <= d; i++) {
        counting_sort(arr, res, n, i);
        memcpy(arr, res, n * sizeof(int)); 
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

    radixsort(arr, res, MAXN, 4);

    for (int j = 0; j < MAXN; j++)
        printf("%d ", arr[j]);
    printf("\n");

    return 0;
}
