//copied
#define INF 0x3f3f3f3f
class Solution {
public:
    
    vector < vector <int> > adj, bridges;
    vector <bool> visited; 
    
    vector <int> disc, low;
    
    void dfs(int u, int parent)
    {
        static int tim = 1;
        disc[u] = low[u] = tim++;
        int child = 0;
        visited[u] = true;
        
        for(auto ele: adj[u])
        {
            if(!visited[ele])
            {
                child++;
                dfs(ele, u);
                low[u] = min(low[u], low[ele]);
                if(low[ele] > disc[u])
                {
                    vector <int> temp;
                    temp.push_back(u);
                    temp.push_back(ele);
                    bridges.push_back(temp);
                }
            }
            else if (ele != parent)
            {
                low[u] = min(low[u], disc[ele]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        adj.resize(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
                
        visited.resize(n, false);
        disc.resize(n, INF);
        low.resize(n, INF);
        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
                
        return bridges;
    }
};


/*
What I'm thinking?
Approach 1:- 
    I am only getting a bruteforce idea that consider each 
    edge as an answer and then remove that edge and check if 
    it gets divided in to two components or not and if yes
    then that is an answer.
    
    But there can 10^5 edges and 10^5 nodes and that will make 
    the algorithm to go for 10^10 times.
    
    TLE will come

Approach 2:-
    For each node mark the current node as visited and then 
    call dfs one child node and then check how many of it's childs 
    are not visited and then store it in 
    ans -> {currentNode,ChildNode}
  
** All these approaches are not good enough to solve the problem


*/