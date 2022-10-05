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
    vector<int> info(TreeNode *root){
        if(!root) return {0,0};  // {sum, countOfNodes}
        int curr = root->val;
        vector<int> leftSub = info(root->left);
        vector<int> rightSub = info(root->right);
        
        int totalNodes = leftSub[1] + rightSub[1] +1;
        int totalSum = leftSub[0]+rightSub[0]+curr;
        
        int avg = totalSum/totalNodes;
        if(avg==curr) ans++;
        
        return {totalSum,totalNodes};
        
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        info(root);
        return ans;
    }
};