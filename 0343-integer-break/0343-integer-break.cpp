class Solution {
public:
    int dp[2][60];
    int getMaxAns(int n,int x=0){
        if(n<=0) return 0;
        if(n==1) return 1;
        if(dp[x][n]!=-1) return dp[x][n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,i*getMaxAns(n-i,1));
            if(x){
                ans=max({ans,i*(n-i),n});
            }
        }
        return dp[x][n]=ans;
    }
    int integerBreak(int n) {
      memset(dp,-1,sizeof(dp));
     return getMaxAns(n);   
    }
};