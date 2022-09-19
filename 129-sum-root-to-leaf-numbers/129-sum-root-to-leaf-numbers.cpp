class Solution {
public:
    int sumNumbers(TreeNode* root,int sum=0) {
        if(!root) return 0;
        if(!root->left and !root->right) return sum*10+root->val;
        int leftNumber = sumNumbers(root->left,sum*10+root->val);
        int rightNumber = sumNumbers(root->right,sum*10+root->val);        
        return leftNumber + rightNumber;
    }
};