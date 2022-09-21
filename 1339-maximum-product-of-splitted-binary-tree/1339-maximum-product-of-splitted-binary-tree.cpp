
class Solution {
public:
    long mod = 1e9+7;
    long long  ans=0;
    long long total=0;
    long long  getSum(TreeNode *root){
       if(!root)  return 0;
       return root->val+getSum(root->left)+getSum(root->right);
    }
    long long  dfs(TreeNode *root){
       if(!root) return 0;
       long long  leftSum = dfs(root->left);
       long long  rightSum = dfs(root->right);
       
        long long ans1 = leftSum * (total-leftSum);
        long long ans2 = rightSum * (total-rightSum);
        long long currMax = max(ans1,ans2);
        ans=max(ans,currMax);
        
        return leftSum+rightSum+root->val;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        total = getSum(root);
        dfs(root);
        return ans%mod;
    }
};