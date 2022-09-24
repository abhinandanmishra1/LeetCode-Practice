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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        findallpaths(root,targetSum,0,path);
        return ans;
    }
    void findallpaths(TreeNode *root,int target,int sum,vector<int> path){
        if(root==NULL){
            return;
        }
        
        if(sum+root->val==target){
            if(root->left==NULL and root->right==NULL){
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
                return;
            }
            
        }
        
        if(root->left!=NULL){
            path.push_back(root->val);
            findallpaths(root->left,target,sum+root->val,path);
            path.pop_back();
        }
        if(root->right!=NULL){
            path.push_back(root->val);
            findallpaths(root->right,target,sum+root->val,path);
            path.pop_back();
        }
        
    }
};