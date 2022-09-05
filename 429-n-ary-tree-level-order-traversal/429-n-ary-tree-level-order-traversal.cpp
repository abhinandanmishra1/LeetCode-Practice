/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int> levelTraverse;
            while(size--){
                auto it = q.front();
                q.pop();
                levelTraverse.push_back(it->val);
                for(auto child:it->children){
                    if(child)
                    q.push(child);
                }
            }
            if(levelTraverse.size()>0){
                ans.push_back(levelTraverse);
            }
        }
        return ans;
    }
};