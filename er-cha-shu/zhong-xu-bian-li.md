# 中序遍历

递归版本：

{% code-tabs %}
{% code-tabs-item title="inorder\_rec.c" %}
```c
#include "treenode.h"

#include <stdio.h>

void
inOrderRec(TreeNode *root)
{
    if (root != NULL) {
        inOrderRec(root->left);
        fprintf(stderr, "%d ", root->data);
        inOrderRec(root->right);
    }
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

非递归版本：

{% code-tabs %}
{% code-tabs-item title="inorder\_ite.c" %}
```c
#include "treenode.h"

#include <stdio.h>

void
inOrderIte(TreeNode *root)
{
    TreeNode *p = root;
    // 栈
    TreeNode* stack[MAXN];
    int size = 0;
    // 循环直至辅助指针为空或栈为空
    while (p != NULL || size != 0) {
        if (p != NULL) {
            // 如果将下面的printf语句挪到此处，中序遍历便变成了前序遍历
            stack[size++] = p;
            p = p->left; // 访问左子树节点，并将其入栈便于回溯
        } else {
            // 以p为根节点的左子树节点遍历完毕，开始打印并出栈回溯
            p = stack[--size];
            fprintf(stdout, "%d ", p->data); // 上面所说的printf语句
            // 开始遍历以p为根节点的右子树
            p = p->right;
        }
    }
}

```
{% endcode-tabs-item %}
{% endcode-tabs %}

测试：

{% code-tabs %}
{% code-tabs-item title="testin.c" %}
```c
#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>

void
inOrderRec(TreeNode *root);

void
inOrderIte(TreeNode *root);

TreeNode*
create();

int
main()
{
    TreeNode *root = create();
    inOrderRec(root);
    inOrderIte(root);
    exit(EXIT_SUCCESS);
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

编译运行，输出重定向\(递归版本输出到stderr，非递归版本输出到stdout）：

> gcc -o testin testin.c tree.c inorder\_rec.c inorder\_ite.c -D MAXN=100
>
> ./testin 1&gt;fileite 2&gt;filerec

