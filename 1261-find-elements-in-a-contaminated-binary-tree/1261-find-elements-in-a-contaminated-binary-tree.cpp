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
class FindElements {
public:
    unordered_map<int,int> mp;
    void dfs(TreeNode *root,int curr=0){
        if(!root) return;
        mp[curr]++;
        dfs(root->left,2*curr+1);
        dfs(root->right,2*curr+2);
    }
    FindElements(TreeNode* root) {
        dfs(root);
    }
    
    bool find(int target) {
        return mp.find(target)!=mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */