
class Solution {
public:
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot,bool checkDirect=false) {
        if(subRoot==NULL and root==NULL) return true;
        if(subRoot==NULL or root==NULL) return false;
        
        if(checkDirect){
            
            if(root->val==subRoot->val){
                // if 
                return (isSubtree(root->left,subRoot->left,true) and isSubtree(root->right,subRoot->right,true));
            }else{
                //If some prev elements are matched but current element is not matched
                return false;
            }
            
        }else{
           if(root->val==subRoot->val){
               return (isSubtree(root->left,subRoot->left,true) and isSubtree(root->right,subRoot->right,true)) or isSubtree(root->left,subRoot,false) or isSubtree(root->right,subRoot,false);
           }else{
               return isSubtree(root->left,subRoot,false) or isSubtree(root->right,subRoot,false);
           }
        }
        
    }
};