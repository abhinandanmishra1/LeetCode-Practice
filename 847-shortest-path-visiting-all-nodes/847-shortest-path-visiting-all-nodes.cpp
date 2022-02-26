class Solution {
public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int ans=INT_MAX;
//         int n=graph.size();
//         for(int start=0;start<n;start++){
//             vector<bool> visited(n,false);
//             queue<int> q;
//             q.push(start);
//             visited[start]=true;
//             int count=0;
//             cout<<"\nFor node = "<<start<<endl;
//             while(!q.empty()){
//                 int k=0;
//                 int i=q.front();
//                 q.pop();
//                 cout<<i<<" ";
//                 auto arr=graph[i];
//                 for(auto x:arr){
//                     if(!visited[x]){
//                         visited[x]=true;
//                         q.push(x);
//                         k++;
//                     }
//                 }
//                 if(k>1)
//                 count+=2*k+1;
//                 else if(k==1)
//                 count++;
                
//             }
//             ans=min(ans,count);
//         }
//         return ans;
//     }
    
      int shortestPathLength(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        queue<pair<int,int>>q;
        int end=(1<<n)-1;
        // vector<vector<int>>vis(n,vector<int>((1<<n),0));
        for(int i=0;i<n;i++)
        {
            q.push({i,1<<i});
        }
        int level=0;
        unordered_set<string>vis;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                   q.pop();
                int node=temp.first;
                int lt=temp.second;
                if(end==lt)
                {
                    return level;
                }
                string key="##"+to_string(node)+"##"+to_string(lt);
                if(vis.find(key)!=vis.end())
                {
                    continue;
                }
                vis.insert(key);
                for(auto it:mat[node])
                {
                    q.push({it,lt|(1<<it)});
                }
            }
            
            level++;
        }
        return 0;
    }
};