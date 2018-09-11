---
description: 这个代码写的并不好，但是现在并不想改
---

# 桶排序

{% file src="../.gitbook/assets/bucketsort.c" caption="bucketsort.c" %}

{% code-tabs %}
{% code-tabs-item title="bucketsort.c" %}
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Node{
    double key;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
}List;

void
insertionsort(List **list);

void
insert(List **list, double key);

void
bucketsort(double arr[], List *res[], int n)
{
    for (int i = 0; i < n; i++)
        res[i] = NULL;
    for (int i = 0; i < n; i++) {
        //printf("地址:%x\n", &res[(int)(n * arr[i])]);
        insert(&res[(int)(n * arr[i])], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        /*
        printf("res[%d]:\n", i);
        if (res[i] == NULL)
            printf("NULL\n\n");
        else {
            Node *node = res[i]->head;
            while (node != NULL) {
                printf("%f ", node->key);
                node = node->next;
            }
            printf("\n\n");
        }
        */ 
        insertionsort(&res[i]);
        /*
        printf("sorted:\n");
        if (res[i] == NULL)
            printf("NULL\n\n");
        else {
            Node *node = res[i]->head;
            while (node != NULL) {
                printf("%f ", node->key);
                node = node->next;
            }
            printf("\n\n");
        }
        */
    }
}

void
insertionsort(List **list)
{
    if (*list == NULL)
        return;

    Node *cur = (*list)->head->next;
    while (cur != NULL) {
        Node *keynode = cur;
        cur = cur->next;
        Node *forward = (*list)->head, *preofforward = NULL;
        while (forward != keynode && forward->key < keynode->key) {
            preofforward = forward;
            forward = forward->next;
        }

        if (forward != keynode) {
            // 查找keynode的前驱
            Node *pre = (*list)->head;
            while (pre->next != keynode) {
                pre = pre->next;
            }
            // 更新keynode的前驱节点
            pre->next = keynode->next;
            // 如果keynode是当前最小的那个
            if (preofforward == NULL) {
                keynode->next = (*list)->head;
                (*list)->head = keynode;
                continue;
            }
            // 插入keynode
            preofforward->next = keynode;
            keynode->next = forward;
        }
    }
}

void
insert(List **list, double key)
{
    if (*list == NULL)
        *list = malloc(sizeof(List));
    // 头插入
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = (*list)->head;
    (*list)->head = node;
    // printf("地址:%x\n\n", list);
}

int
main()
{
    double arr[MAXN];
    List **res = malloc(MAXN * sizeof(List *));

    srand(time(NULL));
    for (int i = 0; i < MAXN; i++) {
        arr[i] = rand() % RAND_MAX / (double)RAND_MAX;
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketsort(arr, res, MAXN);

    for (int i = 0; i < MAXN; i++) {
        if (res[i] == NULL)
            continue;
        else {
            Node *node = res[i]->head;
            while (node != NULL) {
                printf("%f ", node->key);
                node = node->next;
            }
        }
    }
    printf("\n");

    return 0;
    // 退出进程，自动清理分配的内存
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

