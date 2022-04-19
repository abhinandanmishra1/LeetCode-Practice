class Solution {
public:
    vector<int> store;
    int index=0;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);
    }
    void setAns(TreeNode *root){
        if(!root) return;
        setAns(root->left);
        root->val=store[index];
        index++;
        setAns(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        // cout<<store.size();
        sort(store.begin(),store.end());
        setAns(root);
    }
};

// 3 2 1
// 2 3 1
// 1 3 2
// 1 2 3