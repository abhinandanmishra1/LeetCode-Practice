/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode *,TreeNode *> parent;
        queue<TreeNode *> q;
        q.push(root);
        
        // storing the parent of each node so that we can traverse in all direction 
        // like we do in graph 
        // while starting from target node
        parent[root]=root;
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left){
                parent[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent[temp->right]=temp;
                q.push(temp->right);
            }
        }
        // now going in all directions to go to desired distance 
        
        q.push(target);
        int dist=0;
        
        
        unordered_map<TreeNode *,bool> visited;
        visited[target]=true;
        while(!q.empty()){
                if(dist==k) break;
                int size=q.size();
                while(size--){
                    TreeNode *temp=q.front();
                    q.pop();
                    if(temp->left and !visited[temp->left]){
                        visited[temp->left]=true;
                        q.push(temp->left);
                     }
                    if(temp->right and !visited[temp->right]){
                        visited[temp->right]=true;
                        q.push(temp->right);
                     }
                    if(!visited[parent[temp]]){
                        visited[parent[temp]]=true;
                        q.push(parent[temp]);
                     }
                }
            dist++;
            
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};