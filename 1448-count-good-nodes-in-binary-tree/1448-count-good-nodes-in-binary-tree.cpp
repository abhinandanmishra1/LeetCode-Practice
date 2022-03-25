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
    int goodNodes(TreeNode* root,int ma=INT_MIN) {
        if(!root) return 0;
        int ans=(root->val>=ma);
        ans+=goodNodes(root->left,max(ma,root->val));
        ans+=goodNodes(root->right,max(root->val,ma));
        return ans;
    }
};