/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isSymmetricHelper(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right) {
    if (left == NULL && right == NULL)
        return true;
    
    if (left == NULL || right == NULL || left->data != right->data)
        return false;

    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return true;
    
    return isSymmetricHelper(root->left, root->right);
}