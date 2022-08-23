class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int i=1;
        while(i<n){
            grid[0][i]+=grid[0][i-1];
            i++;
        }
        i=1;
        while(i<m){
            grid[i][0]+=grid[i-1][0];
            i++;
        }
        
        for(i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        
        return grid.back().back();
    }
};