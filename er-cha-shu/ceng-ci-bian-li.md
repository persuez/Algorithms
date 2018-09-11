---
description: bfs，代码的正确性已验证
---

# 层次遍历

{% code-tabs %}
{% code-tabs-item title="bfs.c" %}
```c
#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * 二叉树的层次遍历，其实就是对二叉树进行bfs，其中用到了队列
 */
void
bfs(TreeNode *root)
{
    if (root != NULL) {
        int n = MAXN + 1;
        // 用数组模拟队列，就不进行封装了^-^
        TreeNode* queue[n]; // 循环队列的数组实现中浪费一个空间
        // 对头和对尾
        int front = 0, end = 0; // 对空的条件是front == end，队满是(end + 1) % n == front
        // 将根节点入队
        queue[end] = root;
        end = (end + 1) % n;
        // 循环直至队为空
        while (front != end) {
            // 取出队头（下面两句）
            TreeNode *p = queue[front];
            front = (front + 1) % n;
            // 打印队头
            printf("%d ", p->data);
            // 将左右子树入队
            if (p->left != NULL) {
                // 因为这里队列不可能满，所以入队之前就不判满不满了
                queue[end] = p->left;
                end = (end + 1) % n; 
            }
            if (p->right != NULL) {
                queue[end] = p->right;
                end = (end + 1) % n;
            }
        }
    }
    printf("\n");
}

TreeNode*
create();

int
main()
{
    TreeNode *root = create();
    bfs(root);
    exit(EXIT_SUCCESS);
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

