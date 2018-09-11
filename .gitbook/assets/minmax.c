#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
minmax(int arr[], int n, int *pmin, int *pmax)
{
    int min, max;
    if (n % 2 == 1) {
        min = max = arr[0];
        for (int i = 1; i <= n - 2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                if (arr[i] > max)
                    max = arr[i];
                if (arr[i + 1] < min)
                    min = arr[i + 1];
            } else {
                if (arr[i + 1] > max)
                    max = arr[i + 1];
                if (arr[i] < min)
                    min = arr[i];
            }
        }
    } else {
        if (arr[0] > arr[1])
            max = arr[0], min = arr[1];
        else
            max = arr[1], min = arr[0];
        for (int i = 2; i <= n-2; i = i + 2) {
            if (arr[i] > arr[i + 1]) {
                if (arr[i] > max)
                    max = arr[i];
                if (arr[i + 1] < min)
                    min = arr[i + 1];
            } else {
                if (arr[i + 1] > max)
                    max = arr[i + 1];
                if (arr[i] < min)
                    min = arr[i];
            }
        }
    }
    *pmin = min, *pmax = max;
}

int
main()
{
    int arr[MAXN], min, max;
    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    minmax(arr, MAXN, &min, &max);
    printf("min=%d, max=%d\n", min, max);
    return 0;
}
