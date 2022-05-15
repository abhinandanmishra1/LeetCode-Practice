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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            while(size--){
                auto t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            
            if(q.empty()) return sum;
        }
        return 0;
    }
};