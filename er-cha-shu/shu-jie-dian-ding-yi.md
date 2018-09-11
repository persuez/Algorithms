# 随机二叉树生成

定义树节点如下：

{% code-tabs %}
{% code-tabs-item title="treenode.h" %}
```c
#ifndef TREENODE_HPP_
#define TREENODE_HPP_

typedef struct node {
    int data; // 数据
    struct node *left; // 左孩子
    struct node *right; // 右孩子
}TreeNode;
#endif
```
{% endcode-tabs-item %}
{% endcode-tabs %}

create函数生成一颗二叉树，并返回根节点值。我没有写销毁malloc出来的堆内存，而是靠exit退出进程后操作系统自动回收内存。可以用Valgrind查看内存使用情况。

{% code-tabs %}
{% code-tabs-item title="tree.c" %}
```c
#ifndef TREE_H_
#define TREE_H_

#include "treenode.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 以下函数中MAXN宏表示树的节点数, 要求MAXN >= 1, 在编译时-D指定大小
TreeNode*
createNode(int data)
{
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->data = data;
    p->left = p->right = NULL;
    return p;
}
/*
 * 函数功能: 随机创建一颗二叉树, 树节点的data值是顺序从0到MAXN - 1,
 * 具体做法是随机指定一个节点是否有左右子树(每层的节点数至少是半满的, 
 * 这个是通过一个在[0, 2]的随机整数指定--0代表只有左子树, 1代表只有右子树
 * 2代表有左右子树.
 */
TreeNode*
create()
{
    TreeNode *pnode[MAXN];
    pnode[0] = malloc(sizeof(TreeNode));
    pnode[0]->data = 0;
    pnode[0]->left = pnode[0]->right = NULL;

    int cnt = 1, i = 0;
    srand(time(NULL));
    while (cnt < MAXN) {
        int j = rand() % 3;
        switch(j) {
            case 0:
                pnode[cnt] = createNode(cnt);
                pnode[i]->left = pnode[cnt++];
                break;
            case 1:
                pnode[cnt] = createNode(cnt);
                pnode[i]->right = pnode[cnt++];
                break;
            case 2:
                pnode[cnt] = createNode(cnt);
                pnode[i]->left = pnode[cnt++];
                if (cnt == MAXN)
                    break; // 可能这里就有MAXN个节点了
                pnode[cnt] = createNode(cnt);
                pnode[i]->right = pnode[cnt++];
                break;
        } 
        i = i + 1;
    }
    return pnode[0];
}
#endif
```
{% endcode-tabs-item %}
{% endcode-tabs %}

