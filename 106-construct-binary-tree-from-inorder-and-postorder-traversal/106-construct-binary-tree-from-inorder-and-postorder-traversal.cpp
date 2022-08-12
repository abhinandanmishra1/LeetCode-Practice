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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 or postorder.size()==0) return NULL;
        int val=postorder.back();
        postorder.pop_back();
        TreeNode * root=new TreeNode(val);
        int i=0;
        while(inorder[i]!=val) i++;
        vector<int> leftinorder(inorder.begin(),inorder.begin()+i);
        vector<int> leftpostorder(postorder.begin(),postorder.begin()+i);
        root->left=buildTree(leftinorder,leftpostorder);
        vector<int> rightinorder(inorder.begin()+i+1,inorder.end());
        vector<int> rightpostorder(postorder.begin()+i,postorder.end());
        root->right=buildTree(rightinorder,rightpostorder);
        
        return root;
    }
};