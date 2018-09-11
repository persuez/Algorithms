#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void bubble(int arr[], int n)
{
    int round = n - 1; //总共冒泡n-1回

    while (round > 0) {
        int flag = 0; //假设这一轮没有交换
        int low_bound = n - round;
        for (int i = n - 1; i >= low_bound; i--) {
            if (arr[i] < arr[i - 1]) {
                flag = 1;
                swap(&arr[i], &arr[i - 1]);
            } 
        }

        if (!flag) // 这一轮没有交换
            break;
        round = round - 1;
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

    bubble(arr, MAXN);

    for (int i = 0; i < MAXN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
