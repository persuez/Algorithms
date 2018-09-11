---
description: 递归和非递归两个版本，非递归版本通过重定向和对拍脚本与递归版本的运行结果对比，得出非递归版本是正确的。之后关于二叉树的遍历都是这么做的。
---

# 前序遍历

递归版本：

{% code-tabs %}
{% code-tabs-item title="preorder\_rec.c" %}
```c
#include "treenode.h"

#include <stdio.h>

void
preOrderRec(TreeNode *root)
{
    if (root != NULL) {
        fprintf(stderr, "%d ", root->data);
        preOrderRec(root->left);
        preOrderRec(root->right);
    }
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

非递归版本（思路代码注释中有详解，通过栈来实现）：

{% code-tabs %}
{% code-tabs-item title="preorder\_ite.c" %}
```c
#include "treenode.h"

#include <stdio.h>

void
preOrderIte(TreeNode *root)
{
    if (root != NULL) {
        // 辅助数组，相当于栈
        TreeNode* stack[MAXN];
        // 栈的长度，初始为0
        int size = 0;
        // 将根节点入栈
        stack[size++] = root;
        // 循环直至栈为空
        while (size != 0) {
            // 取出栈顶元素，并打印
            TreeNode *p = stack[--size];
            fprintf(stdout, "%d ", p->data);
            // 先将右节点（如果存在）入栈
            if (p->right != NULL)
                stack[size++] = p->right;
            // 再将左节点（如果存在）入栈
            if (p->left != NULL)
                stack[size++] = p->left;
        }
    }
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

测试代码：

{% code-tabs %}
{% code-tabs-item title="testpre.c" %}
```c
#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>

TreeNode*
create();

void
preOrderRec(TreeNode *);

void
preOrderIte(TreeNode *);

int
main()
{
    TreeNode *root = create();
    preOrderRec(root);
    preOrderIte(root);
    exit(EXIT_SUCCESS);
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

编译运行，输出重定向\(递归版本输出到stderr，非递归版本输出到stdout）：

> gcc -o testpre testpre.c tree.c preorder\_rec.c preorder\_ite.c -D MAXN=100
>
> ./testpre 1&gt;fileite 2&gt;filerec

对拍：

> chmod a+x compare.sh; ./compare.sh filerec fileite

