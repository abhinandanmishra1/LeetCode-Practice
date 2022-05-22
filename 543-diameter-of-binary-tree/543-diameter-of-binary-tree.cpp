class Solution {
public:
    int ans=0;
    int findDiameter(TreeNode *root){
        if(!root) return 0;
        // findDiameter returns the height of the tree
        // if we know height of both left and right tree 
        // then we can store the ans = max(ans,left+right+1)
        int leftHeight=findDiameter(root->left);
        int rightHeight=findDiameter(root->right);
        
        ans=max(ans,leftHeight+rightHeight);
        
        return max(leftHeight,rightHeight)+1; // as height of a tree is maximum height of left or right subtree + 1
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root);
        return ans;
    }
};