#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int>* root, int key) {
    int ceilValue = -1;
    while (root != nullptr) {
        if (root->data == key) {
            ceilValue = key;
            break;
        } else if (root->data > key) {
            ceilValue = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceilValue;
}

// void findCeilInorder(BinaryTreeNode<int>* node, int key, int& ceilValue) {
//     if (node == nullptr)
//         return;

//     if (node->data == key) {
//         ceilValue = key;
//         return;
//     }

//     if (node->data > key) {
//         ceilValue = node->data;
//         findCeilInorder(node->left, key, ceilValue);
//     } else {
//         findCeilInorder(node->right, key, ceilValue);
//     }
// }

// int findCeil(BinaryTreeNode<int>* root, int key) {
//     int ceilValue = -1;
//     findCeilInorder(root, key, ceilValue);
//     return ceilValue;
// }
