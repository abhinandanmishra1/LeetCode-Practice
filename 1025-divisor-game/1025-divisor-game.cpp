class Solution {
public:
    vector<int> dp;
    int findans(int n,int t){
        int ans=(t==0)?1:0;
        if(n==1) return ans;
        if(n==2) return t;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(i==1){
                if(findans(n-1,ans)==t){
                    return dp[n]=t;
                }
                continue;
            }
            if(i*i==n){
                if(findans(n-i,ans)==t){
                    return dp[n]=t;
                }
                continue;
            }
            if(n%i==0){
                if(findans(n-i,ans)==t){
                    return dp[n]=t;
                }
                if(findans(n-(n/i),ans)==t){
                    return dp[n]=t;
                }
            }
        }
        
        return dp[n]=ans;
    }
    bool divisorGame(int n) {
        dp.resize(n+1,-1);
        return findans(n,1);
    }
};