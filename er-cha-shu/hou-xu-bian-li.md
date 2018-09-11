# 后序遍历

递归版本：

{% code-tabs %}
{% code-tabs-item title="posrorder\_rec.c" %}
```c
#include "treenode.h"

#include <stdio.h>

void
postOrderRec(TreeNode *root)
{
    if (root != NULL) {
        postOrderRec(root->left);
        postOrderRec(root->right);
        fprintf(stderr, "%d ", root->data);
    }
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

非递归版本，思路在代码中：

{% code-tabs %}
{% code-tabs-item title="postorder\_ite.c" %}
```c
#include "treenode.h"

#include <stdio.h>

/*
 * 后序遍历思路：类似之前文中前序遍历的实现，但是又有所变化。
 * 这是因为后序遍历类似于前序遍历：先访问左子树，然后访问右子树，
 * 再访问根节点;换种角度看，后序遍历是以下遍历的逆序：先访问根节点，
 * 然后访问右子树，再访问左子树，是不是和前序遍历很像？因此我用两个栈
 * 来实现后序遍历，一个用来类似前序遍历的访问，一个用于作为逆序的输出（
 * 也就是当访问前一个栈的栈顶元素时，前序遍历是直接打印的，但是由于后序
 * 遍历需要逆序打印，所以先保存在一个栈中
 */
void
postOrderIte(TreeNode *root)
{
    if (root != NULL) {
        // 类似前序的栈stack和用于输出的栈output
        TreeNode *stack[MAXN], *output[MAXN];
        // 栈大小：size1和size2
        int size1 = 0, size2 = 0;
        // 根节点入栈
        stack[size1++] = root;
        // 循环直至栈stack为空
        while (size1 != 0) {
            // 出栈并压入output
            TreeNode *p = stack[--size1];
            output[size2++] = p;
            // 按和前序遍历相反的顺序对左子树和右子树压栈
            // 即先左再右
            if (p->left != NULL)
                stack[size1++] = p->left;
            if (p->right != NULL)
                stack[size1++] = p->right; 
        }
        // 输出
        while (size2 != 0) {
            fprintf(stdout, "%d ", output[--size2]->data);
        } 
    } 
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

测试省略（已测过，懒得重复了）

