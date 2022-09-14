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
    void findans(TreeNode *root,vector<int>& arr){
        if(!root) return;
        if(!root->left and !root->right){
            int check=0;
            arr[root->val]++;
            for(int i=1;i<=9;i++){
                if(arr[i]&1) check++;
                if(check>1){
                    break;
                }
            }
            if(check<=1) ans++;
            arr[root->val]--;
            return;
        }
        
        arr[root->val]++;
        findans(root->left,arr);
        arr[root->val]--;
        arr[root->val]++;
        findans(root->right,arr);
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10,0);
        findans(root,arr);
        return ans;
    }
};