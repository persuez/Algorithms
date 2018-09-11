# 前（后）序遍历和中序遍历生成（还原）二叉树

这里只写前序+中序还原二叉树，后序+中序类似：

{% code-tabs %}
{% code-tabs-item title="recoverfromwalk.c" %}
```c
#include "treenode.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * 从前（后）序遍历和中序遍历还原二叉树(key值互不相同），为什么可以呢？
 * 就前序遍历来说，它的第一个节点是根节点，由此我们可以在中序遍历中
 * 找出左右子树（如果存在的话），然后我们可以根据左右子树的长度对应找出
 * 它们在前序遍历中的位置，这样我们就可以用相同的算法（递归）求出
 * 左右子树的具体分布。
 * 参数：两个数组分别提供前中序遍历的结果，ps和pe表示子树在前序遍历中的
 * 范围，is和ie则表示子树在中序遍历中的范围(都是闭区间）
 */
TreeNode*
recoverFromWalk(int pre[], int in[], int ps, int pe, int is, int ie)
{
    // 根节点为前序遍历中的第一个节点
    TreeNode *root = malloc(sizeof(TreeNode));
    root->data = pre[ps];
    root->left = root->right = NULL;
    // 如果当前探索序列中只有一个节点了，那么就返回它（base条件）
    if (ps == pe)
        return root;
    // 不然就在中序数组中找到根节点
    int i;
    for (i = is; i <= ie; i++) {
        if (in[i] == root->data) {
            break;
        }
    } 
    // 分别求出左右子树的长度(在中序遍历的结果中求）
    int len_left = i - is;
    int len_right = ie - i;
    if (len_left > 0)
        root->left = recoverFromWalk(pre, in, ps + 1, ps + len_left, is, i - 1);
    if (len_right > 0)
        root->right = recoverFromWalk(pre, in, ps + len_left + 1, pe, i + 1, ie);
    return root;
}

void
preOrderRec(TreeNode *);

void
inOrderRec(TreeNode *);

void
postOrderRec(TreeNode *);

int
main()
{
    // 懒得修改之前的前序遍历和中序遍历，就不做随机化测试了
    // 随便画的一棵树
    int pre[10] = {0, 1, 3, 6, 9, 7, 2, 4, 8, 5};
    int in[10] = {6, 9, 3, 7, 1, 0, 8, 4, 2, 5};
    TreeNode *root = recoverFromWalk(pre, in, 0, 9, 0, 9);
    preOrderRec(root);
    printf("\n");
    inOrderRec(root);
    printf("\n");
    postOrderRec(root);
    printf("\n");
    exit(EXIT_SUCCESS);    
}
```
{% endcode-tabs-item %}
{% endcode-tabs %}

