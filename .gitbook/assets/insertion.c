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
