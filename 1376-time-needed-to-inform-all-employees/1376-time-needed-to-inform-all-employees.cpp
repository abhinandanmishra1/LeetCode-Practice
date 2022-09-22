class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edges(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            edges[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int currTime=0;
            while(size--){
                auto curr = q.front();
                int node = curr.first;
                int prevTime = curr.second;
                q.pop();
                for(int n:edges[node]){
                    q.push({n,prevTime+informTime[node]});
                }
                currTime = max(currTime,prevTime);
            }
            ans=max(currTime,ans);
        }
        return ans;
    }
};