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
    void findans(TreeNode *root,vector<string>&ans,string s){
        if(!root){
            return;
        }
        s.append(to_string(root->val));
        s.append("->");
        findans(root->left,ans,s);
        findans(root->right,ans,s);
        if(!root->right and !root->left){
            if(s.back()=='>') s.pop_back();
            if(s.back()=='-') s.pop_back();
            ans.push_back(s);
        }        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findans(root,ans,"");
        return ans;
    }
};