class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long int>> dp(n,vector<long long int>(amount+1,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<amount+1;j++){
                if(j==0){
                    dp[i][j]=0;
                }else{
                    if(i!=0){
                        dp[i][j]=dp[i-1][j];
                    }
                    if(j>=coins[i])
                    dp[i][j]=min(dp[i][j],dp[i][j-coins[i]]+1);
                }
            }
        }
        return dp[n-1][amount]==INT_MAX?-1:dp[n-1][amount];
    }
};