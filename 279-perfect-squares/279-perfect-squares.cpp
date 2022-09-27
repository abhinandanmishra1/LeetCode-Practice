class Solution {
public:
    vector<int> dp;
    Solution(){
        dp.resize(10005,-1);
    }
    int numSquares(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+numSquares(n-i*i));
        }
        return dp[n]=ans;
    }
};