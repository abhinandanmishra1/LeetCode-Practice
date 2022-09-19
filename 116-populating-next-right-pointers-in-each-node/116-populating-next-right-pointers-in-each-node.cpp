class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            size--;
            while(size--){
                Node* front = q.front();
                q.pop();
                front->next = q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            q.front()->next = NULL;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        return root;
    }
};