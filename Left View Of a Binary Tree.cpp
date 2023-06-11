#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int>* root) {

    vector<int> ans;
    if(root == NULL) return ans;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            TreeNode<int>* curr = q.front();
            q.pop();
            
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
    return ans; 
}