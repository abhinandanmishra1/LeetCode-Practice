class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int minSum(vector<vector<int>> &matrix,int i,int j){
        if(i<0 or i>=n or j<0 or j>=m){
            return INT_MAX;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=minSum(matrix,i+1,j-1);
        int right=minSum(matrix,i+1,j+1);
        int down=minSum(matrix,i+1,j);
        int ans=min({left,right,down});
        if(ans==INT_MAX) ans=0;
        return dp[i][j]=matrix[i][j]+ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,minSum(matrix,0,j));
        }
        return ans;
    }
};