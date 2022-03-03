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
    bool isSubtree(TreeNode* root, TreeNode* subRoot , bool check=true) {
        if(root==NULL and subRoot==NULL) return true;
        if(!root or !subRoot) return false;
        bool ans=false;
        if(root->val == subRoot->val){
            ans=isSubtree(root->left,subRoot->left,false) and isSubtree(root->right,subRoot->right,false);
        }
            return ans or (check and (isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot) ));
        
    }
};