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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode *> q;
        int k=0;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            while(size--){
                TreeNode *temp=q.front();
                q.pop();
                level.push_back(temp->val);
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                
            }
            if(k){
                reverse(level.begin(),level.end());
            }
            k^=1;
            ans.push_back(level);
        }
        return ans;
    }
};