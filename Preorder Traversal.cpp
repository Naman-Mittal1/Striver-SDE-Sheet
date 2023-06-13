#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void PreOrderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    result.push_back(root->data);
    PreOrderTraversal(root->left, result);
    PreOrderTraversal(root->right, result);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> result;
    PreOrderTraversal(root, result);
    return result;
}
