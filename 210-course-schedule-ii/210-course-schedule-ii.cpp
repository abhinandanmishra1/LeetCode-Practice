class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<int> vis,dfsVis;
    stack<int> st;
    void dfs(int node){
        if(visited[node]) return;
        visited[node]=true;
        for(auto child:graph[node]){
            dfs(child);
        }
        st.push(node);
    }
    bool cycle(int node){
          vis[node] = 1;
          dfsVis[node] = 1;
          for (auto it: graph[node]) {
            if (!vis[it]) {
              if (cycle(it)) return true;
            } else if (dfsVis[it]) {
              return true;
            }
          }
          dfsVis[node] = 0;
          return false;
    }
    bool isCyclic(int n){
        vis.resize(n,0);
        dfsVis.resize(n,0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
              if (cycle(i)) {
                return true;
              }
            }
        }
      return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
        graph.resize(n);
        
        vector<int> parent(n,-1);
        for( auto x:pq){
            graph[x[1]].push_back(x[0]);
            parent[x[0]]=x[1];
        }
        if(isCyclic(n)) return {};
        visited.resize(n,false);
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                dfs(i);
            }
        }
        
        if(st.size()<n) return {};
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};