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
    int sumOfLeftLeaves(TreeNode* root,bool f=false) {
       if(root==NULL) return 0;
        int ans=0;
       if(f and root->left==NULL and root->right==NULL){
           ans+=root->val;
       }
       ans+=sumOfLeftLeaves(root->left,true);
       ans+=sumOfLeftLeaves(root->right,false);
        return ans;
    }
};