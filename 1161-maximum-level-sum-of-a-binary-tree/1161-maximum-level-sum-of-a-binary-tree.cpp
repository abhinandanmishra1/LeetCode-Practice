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
    int maxLevelSum(TreeNode* root) {
        int index=0;
        int maxSum=INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            int size=q.size();
            int currLevelSum=0;
            while(size--){
                auto currNode = q.front();
                currLevelSum+= currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
                q.pop();
            }
            if(currLevelSum>maxSum){
                maxSum=currLevelSum;
                index = level;
            }
            level++;
        }
        return index;
    }
};