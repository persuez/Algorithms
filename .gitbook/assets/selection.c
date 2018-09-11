#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimun(int arr[], int low, int high)
{
    int min_value = arr[low], min_index = low;

    for (int i = low + 1; i <= high; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        } 
    }
    return min_index;
}

void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void selection(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int j = minimun(arr, i, n - 1);
        if (i != j) {
            swap(&arr[i], &arr[j]);
        }
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

    selection(arr, MAXN);

    for (int i = 0; i < MAXN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
