
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        auto ans = inorderTraversal(root->left);
        ans.push_back(root->val);
        auto rightTree = inorderTraversal(root->right);
        for(auto x:rightTree){
            ans.push_back(x);
        }
        return ans;
    }
};