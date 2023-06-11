#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto frontNode = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Insert the horizontal distance and node value into the map
        if (mp.find(hd) == mp.end()) {
            mp[hd] = frontNode->val;
        }

        if (frontNode->left) {
            q.push({frontNode->left, hd - 1});
        }

        if (frontNode->right) {
            q.push({frontNode->right, hd + 1});
        }
    }

    // Populate the result vector with the node values in top view
    for (const auto& pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
}