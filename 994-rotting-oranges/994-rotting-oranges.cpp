class Solution {
public:
    int n,m;
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        bool flag=false;
        queue<vector<int>> rotten;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotten.push({i,j,0});
                }
                if(grid[i][j]==1) flag=true;
            }
        }
        if(!flag) return 0;
        int ans=0;
        while(!rotten.empty()){
            auto arr=rotten.front();
            int x=arr[0],y=arr[1],z=arr[2];
            rotten.pop();
            for(int i=0;i<4;i++){
                int X=x+a[i];
                int Y=y+b[i];
                if(X<0 or X>=n or Y<0 or Y>=m) continue;
                if(grid[X][Y]==1){
                    grid[X][Y]=2;
                    rotten.push({X,Y,z+1});
                    ans=max(ans,z+1);
                }
            }
        }
        for(auto x:grid){
            for(auto y:x){
                if(y==1) return -1;
            }
        }
        return ans;
    }
};