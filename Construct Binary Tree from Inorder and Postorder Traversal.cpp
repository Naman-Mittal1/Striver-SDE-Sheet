/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

TreeNode<int>* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd)
        return NULL;

    TreeNode<int>* root = new TreeNode<int>(postorder[postEnd]);
    int rootIndex = inStart;
    while (inorder[rootIndex] != postorder[postEnd])
        rootIndex++;

    int leftSubtreeSize = rootIndex - inStart;
    int rightSubtreeSize = inEnd - rootIndex;

    root->left = buildTree(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSubtreeSize - 1);
    root->right = buildTree(inorder, rootIndex + 1, inEnd, postorder, postEnd - rightSubtreeSize, postEnd - 1);

    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) {
    int n = postOrder.size();
    return buildTree(inOrder, 0, n - 1, postOrder, 0, n - 1);
}
