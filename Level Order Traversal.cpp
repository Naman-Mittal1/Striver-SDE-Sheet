/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> result;

    if(root == NULL)
        return result;
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }

    return result;
}