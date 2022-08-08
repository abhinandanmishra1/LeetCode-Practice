/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void findsum(TreeNode *root,int curr){
        if(!root) return;
        if(!root->left and !root->right){
            // cout<<curr<<endl;
            ans.push_back(curr*10+root->val);
            return;
        }
        int currSum=curr*10+root->val;
        if(root->left)
        findsum(root->left,currSum);
        if(root->right)
        findsum(root->right,currSum);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right){
            ans.push_back(root->val);
        }
        findsum(root->left,root->val);
        findsum(root->right,root->val);
        int total=0;
        for(auto x:ans) total+=x;
        return total;
    }
};