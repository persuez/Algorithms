#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[MAXN];

int
left(int i)
{
    return (i << 1) + 1;
}

int
right(int i)
{
    return (i + 1) << 1;
}

void
swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void
max_heapify(int arr[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        max_heapify(arr, n, largest);
    }
}

void
build_max_heap(int arr[], int n)
{
    for (int i = (n - 1) >> 1; i >=0 ; i--)
        max_heapify(arr, n, i);
}

void
heap_sort(int arr[], int n)
{
    build_max_heap(arr, n);

    int heapSize = n;
    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heapSize = heapSize - 1;
        max_heapify(arr, heapSize, 0);
    }
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

    heap_sort(arr, MAXN);

    for (int j = 0; j < MAXN; j++)
        printf("%d ", arr[j]);
    printf("\n");

    return 0;
}
