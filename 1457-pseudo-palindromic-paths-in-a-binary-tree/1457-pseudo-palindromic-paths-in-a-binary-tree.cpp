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
    bool isPseudoPalindromic(vector<int> &count){
        int oddCount=0;
        for(int i=1;i<10;i++){
            oddCount+=count[i]&1;
            if(oddCount>1) return false;
        }
        return true;
    }
    int countPseudoPalindromicPaths(TreeNode *root,vector<int> &count){
        if(!root){
            return 0;
        }
        if(!root->left and !root->right){
            count[root->val]++;
            int ans = isPseudoPalindromic(count);
            count[root->val]--;
            return ans;
        }
        count[root->val]++;
        int leftAns=countPseudoPalindromicPaths(root->left,count);
        int rightAns=countPseudoPalindromicPaths(root->right,count);
        count[root->val]--;
        return leftAns+rightAns;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        return countPseudoPalindromicPaths(root,count);
    }
};