class Solution {
public:
    unordered_map<int,int> mp;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        int v=root->val;
        if(mp.find(k-v)!=mp.end()){
            return true;
        }
        mp[v]++;
        bool ans1,ans2;
        ans1=findTarget(root->left,k);
        ans2=findTarget(root->right,k);
        return ans1 or ans2;
    }
};