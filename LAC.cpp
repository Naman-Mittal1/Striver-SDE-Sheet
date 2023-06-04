bool findPath(TreeNode<int> *root, int key, vector<int>& path)
{
    if (root == NULL) {
        return false;
    }
    path.push_back(root->data);

    if (root->data == key) {
        return true;
    }

    if (findPath(root->left, key, path) || findPath(root->right, key, path)) {
        return true;
    }

    path.pop_back();
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    vector<int> path1, path2;
    if (!findPath(root, x, path1) || !findPath(root, y, path2)) {
        return -1;
    }

    int i = 0;
    while (i < path1.size() && i < path2.size()) {
        if (path1[i] != path2[i]) {
            break;
        }
        i++;
    }

    return path1[i - 1];
}



//Second approach
