class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int findsum(vector<vector<int>> &triangle,int i,int j){
        if(i>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=findsum(triangle,i+1,j);
        int right=findsum(triangle,i+1,j+1);
        int ans=min(left,right);
        if(ans==INT_MAX) ans=0;
        return dp[i][j]=triangle[i][j]+ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return findsum(triangle,0,0);
    }
};