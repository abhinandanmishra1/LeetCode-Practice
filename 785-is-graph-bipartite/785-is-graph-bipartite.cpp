class Solution {
public:
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.resize(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int> q;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                int nextColor=!color[t];
                for(auto x:graph[t]){
                    
                    if(color[x]==-1){
                        color[x]=nextColor;
                        q.push(x);
                    }else{
                        if(color[x]!=nextColor) return false;
                    }
                }
            }
                }
        }
        return true;
    }
};