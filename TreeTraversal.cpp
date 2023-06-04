void inorderTraversal(BinaryTreeNode<int> *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

void preorderTraversal(BinaryTreeNode<int> *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    result.push_back(root->data);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

void postorderTraversal(BinaryTreeNode<int> *root, vector<int> &result) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> traversals;
    vector<int> inorder, preorder, postorder;

    inorderTraversal(root, inorder);
    preorderTraversal(root, preorder);
    postorderTraversal(root, postorder);

    traversals.push_back(inorder);
    traversals.push_back(preorder);
    traversals.push_back(postorder);

    return traversals;
}