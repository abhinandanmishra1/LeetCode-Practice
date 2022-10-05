
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root,int parent=1,int grand=1) {
        if(!root) return 0;
        
        if(!(grand&1)) return root->val+ sumEvenGrandparent(root->left,root->val,parent) + sumEvenGrandparent(root->right,root->val,parent);
        
        return sumEvenGrandparent(root->left,root->val,parent) + sumEvenGrandparent(root->right,root->val,parent);
    }
};