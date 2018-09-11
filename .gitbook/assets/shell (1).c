#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int arr[MAXN];

void shell(int arr[], int n)
{
    int t1 = ceil(2 * (log(1 + sqrt(1 + 4 * (n - 3) * 0.1 / 27)) / log(2)) - 2);
    int t2 = ceil(2 * (log(3 + sqrt(9 + 4 * (n - 3) * 0.1 / 3)) / log(2)) - 5);
    t1 = (t1 % 2 == 0) ? (t1 - 2) : (t1 - 1);
    t2 = (t2 % 2 != 0) ? (t2 - 2) : (t2 - 1);
    int t = (t1 > t2) ? t1 : t2;
    if (t < 0)
        t = 0;
    printf("t1=%d,t2=%d,t=%d\n", t1, t2, t);

    int gap;
    for (int i = t; i >= 0; i--) {
        if (i % 2 == 0)
           gap = 9 * ((2 << i) - (2 << (i >> 1))) + 1;
        else
           gap = (2 << (i + 3)) - 6 * (2 << ((i + 1) >> 1)) + 1;

        for (int j = gap; j < n; j++) {
            int k = j - gap, key = arr[j];
            while (k >= 0 && key < arr[k]) {
                arr[k + gap] = arr[k];
                k = k - gap;
            }
            arr[k + gap] = key;
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

    shell(arr, MAXN);

    for (int i = 0; i < MAXN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
