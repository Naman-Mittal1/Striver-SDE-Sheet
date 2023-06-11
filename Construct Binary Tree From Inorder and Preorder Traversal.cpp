#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
    Inoder = left root right
    preorder = root left right

************************************************************/
TreeNode<int> *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart) {
    if (inStart > inEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);

    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }

    root->left = buildTree(inorder, inStart, rootIndex - 1, preorder, preStart + 1);
    root->right = buildTree(inorder, rootIndex + 1, inEnd, preorder, preStart + (rootIndex - inStart + 1));

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    return buildTree(inorder, 0, inorder.size() - 1, preorder, 0);
}
