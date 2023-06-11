#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

// void inOrder(BinaryTreeNode<int>* root, vector<int> &ans)
// {
//     if(root==NULL)
//         return;
    
//     inOrder(root->left, ans);
//     ans.push_back(root->data);
//     inOrder(root->right, ans);
// }

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if((root1 == NULL && root2 != NULL) ||(root1 != NULL && root2 == NULL))
        return false;
    if(root1 == NULL && root2 == NULL){
        return true;
    } 
    if(root1->data != root2->data){
        return false;
    }
    bool leftAns = identicalTrees(root1->left, root2->left);
    bool rightAns = identicalTrees(root1->right, root2->right);

    return leftAns && rightAns;
}