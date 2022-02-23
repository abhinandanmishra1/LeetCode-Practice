

class Solution {
public:
    Node* cloneGraph(Node* node) {
       
        if(node==NULL) return NULL;
        Node *graph=new Node(node->val,{});
        unordered_map<Node *,Node *> mp;
        mp[node]=graph;
        queue<Node *> q;
        q.push(node);
        while(!q.empty()){
            Node * temp=q.front();
            q.pop();
            auto arr=temp->neighbors;
            
            for(auto x:arr){
                if (mp.find(x) ==mp.end()) {
                    mp[x] = new Node(x -> val, {});
                    q.push(x);
                }
                mp[temp] -> neighbors.push_back(mp[x]);
            }
        }
        return graph;
    }
};