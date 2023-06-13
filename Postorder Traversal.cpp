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



void PostOrderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left, result);
    PostOrderTraversal(root->right, result);
    result.push_back(root->data);

}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> result;
    PostOrderTraversal(root, result);
    return result;
}
