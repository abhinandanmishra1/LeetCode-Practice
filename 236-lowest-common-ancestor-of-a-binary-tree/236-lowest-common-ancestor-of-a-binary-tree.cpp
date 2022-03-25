// if both the nodes are on left then lca is also on left tree // find in left 
// if both are right same thing 
// if one node is on left and other one is on right then root is the answer

// if root is equal to any node then it's the answer

class Solution {
public:
    bool find(TreeNode *root,TreeNode *node){
        if(root==NULL) return false;
        
        if(root==node) return true;
        return find(root->left,node) or find(root->right,node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        
        if(root==p or root==q) return root;
        
        bool rp=find(root->right,p);
        bool lp=find(root->left,p);
        bool rq=find(root->right,q);
        bool lq=find(root->left,q);
        
        if(rp and rq){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(lp and lq){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};