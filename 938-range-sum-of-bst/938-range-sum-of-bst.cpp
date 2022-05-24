class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int ans=0;
        if(root->val<low){
            ans+=rangeSumBST(root->right,low,high);
        }else if(root->val>high){
            ans+=rangeSumBST(root->left,low,high);
        }else{
            ans+=root->val;
            ans+=rangeSumBST(root->right,low,high);
            ans+=rangeSumBST(root->left,low,high);
        }
        return ans;
    }
};