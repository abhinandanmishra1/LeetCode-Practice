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
    vector<unordered_map<TreeNode *,int>> dp;
    Solution(){
        dp.resize(2);
    }
    int rob(TreeNode* root, int i=0) {
        if(!root) return 0;
        if(dp[i].find(root)!=dp[i].end()) return dp[i][root];
        if(!i){
            int sum1= root->val+rob(root->left,1)+rob(root->right,1);
            int sum2= rob(root->left,0)+rob(root->right,0);
            return dp[i][root] = max(sum1,sum2);
        }
        return dp[i][root] = rob(root->left,0)+rob(root->right,0);
    }
};