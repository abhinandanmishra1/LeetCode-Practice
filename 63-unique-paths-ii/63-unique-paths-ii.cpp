class Solution {
public:
    vector<vector<int>> dp;
    Solution(){
        dp.resize(105,vector<int>(105,-1));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs,int i=0,int j=0) {
        int n=obs.size();
        int m=obs[0].size();
        if(obs[n-1][m-1]) return 0;
        if(i==n-1 and j==m-1){
            return 1;
        }
        if(i>=n or j>=m or obs[i][j]) return 0;
        if(dp[i][j]==-1){
            dp[i][j]=uniquePathsWithObstacles(obs,i+1,j)+uniquePathsWithObstacles(obs,i,j+1);
        }
        return dp[i][j];
    }
};