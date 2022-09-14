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
    int ans=0;
    void findans(TreeNode *root,long int path){
        if(!root) return;
        if(!root->left and !root->right){
            path=path^(1<<root->val);
            if(__builtin_popcount(path)<=1) ans++;
            return;
        }
        findans(root->left,path^(1<<root->val));
        findans(root->right,path^(1<<root->val));
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        long int path=0;
        findans(root,path);
        return ans;
    }
};