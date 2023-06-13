#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findPredecessorSuccessor(BinaryTreeNode<int>* root, int key, int& predecessor, int& successor) {
    if (root == NULL)
        return;

    if (root->data == key) {
        if (root->left != NULL) {
            BinaryTreeNode<int>* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            predecessor = temp->data;
        }

        if (root->right != NULL) {
            BinaryTreeNode<int>* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            successor = temp->data;
        }

        return;
    }

    if (key < root->data) {
        successor = root->data;
        findPredecessorSuccessor(root->left, key, predecessor, successor);
    } else {
        predecessor = root->data;
        findPredecessorSuccessor(root->right, key, predecessor, successor);
    }
}

pair<int, int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    int predecessor = -1;
    int successor = -1;

    findPredecessorSuccessor(root, key, predecessor, successor);

    return make_pair(predecessor, successor);
}
