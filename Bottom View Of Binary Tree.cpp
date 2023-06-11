#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
    };

*************************************************************/


vector<int> bottomView(BinaryTreeNode<int> *root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> mp;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto frontNode = q.front().first;
        int hd = q.front().second;
        q.pop();

        mp[hd] = frontNode->data;

        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }

        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    for (const auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}