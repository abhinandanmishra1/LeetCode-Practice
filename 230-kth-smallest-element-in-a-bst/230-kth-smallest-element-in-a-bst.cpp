class Solution {
	vector<int>v;
public:
	void inorder(TreeNode* root)
	{
		if(root==NULL) return;
		inorder(root->left);
		v.push_back(root->val);
		inorder(root->right);
	}
	int kthSmallest(TreeNode* root, int k) {
		inorder(root);
		return v[k-1];
	}
};