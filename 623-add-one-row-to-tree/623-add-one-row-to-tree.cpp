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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,int curr=1) {
        if(!root) return root;
        if(depth==curr){
            if(curr==1){
                TreeNode *newRoot = new TreeNode(val);
                newRoot->left=root;
                return newRoot;
            }
        }
        
        if(depth==curr+1){
            TreeNode *leftTree = new TreeNode(val);
            leftTree->left = root->left;
            TreeNode *rightTree = new TreeNode(val);
            rightTree->right = root->right;
            root->left = leftTree;
            root->right = rightTree;
            
            return root;
        }
        
        root->left = addOneRow(root->left,val,depth,curr+1);
        root->right = addOneRow(root->right,val,depth,curr+1);
        return root;
    }
};