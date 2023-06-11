#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


vector<int> pathInATree(TreeNode<int> *root, int x)
{

	vector<int> ans;
    if(root == NULL)
		return ans;
	
	if (root->data == x) {
        ans.push_back(root->data);
        return ans;
    }

	vector<int> left = pathInATree(root->left, x);
	if (!left.empty()) {
        ans.push_back(root->data);
        ans.insert(ans.end(), left.begin(), left.end());
        return ans;
    }
	vector<int> right = pathInATree(root->right, x);
	if (!right.empty()) {
        ans.push_back(root->data);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

	return ans;
}
