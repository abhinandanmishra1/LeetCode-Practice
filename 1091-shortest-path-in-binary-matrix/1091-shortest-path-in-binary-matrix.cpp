class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{1,-1},{1,1},{-1,0},{-1,-1},{-1,1},{0,-1},{0,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid,int i=0,int j=0) {
        if(grid[0][0]!=0) return -1;
        if(grid.back().back()!=0) return -1;
       
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=-1;
        int n=grid.size();
        int len=1;
        if(n==1) return 1;
        while(!q.empty()){
            int size=q.size();
            len++;
            while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto x:directions){
                    int newI=i+x.first;
                    int newJ=j+x.second;

                    if(newI<0 or newI>=n or newJ<0 or newJ>=n or grid[newI][newJ]!=0) continue;
                    q.push({newI,newJ});
                    grid[newI][newJ]=-1;
                    if(newI==n-1 and newJ==n-1) return len;
                }
            }
        }
        return -1;
    }
};