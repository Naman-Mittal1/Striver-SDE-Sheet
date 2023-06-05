#include <bits/stdc++.h>

using namespace std;

/*************************************************************
 
    Following is the Binary Tree node structure

    template<typename T>
    class BinaryTreeNode 
    {
    public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> convertHelper(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return {NULL, NULL};
    }

    // Convert the left subtree
    pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> leftList = convertHelper(root->left);

    // Convert the right subtree
    pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> rightList = convertHelper(root->right);

    // Create a doubly linked list node for the current root
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root->data);

    // Make the left subtree of root as the previous node
    newNode->left = leftList.second;
    
    // If the left subtree is not empty, set its right pointer to the current node
    if (leftList.second != NULL) {
        leftList.second->right = newNode;
    }

    // Make the right subtree of root as the next node
    newNode->right = rightList.first;

    // If the right subtree is not empty, set its left pointer to the current node
    if (rightList.first != NULL) {
        rightList.first->left = newNode;
    }

    // Find the head and tail of the doubly linked list
    BinaryTreeNode<int>* head = (leftList.first != NULL) ? leftList.first : newNode;
    BinaryTreeNode<int>* tail = (rightList.second != NULL) ? rightList.second : newNode;

    return {head, tail};
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return NULL;
    }

    pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*> result = convertHelper(root);
    return result.first;
}