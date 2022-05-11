class Solution {
public:
    vector<vector<int>> dp;
    Solution(){
        dp.resize(55);
        for(int i=0;i<55;i++){
            dp[i].resize(6,-1);
        }
    }
    int countVowelStrings(int n,int k=5) {
        if(n==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int ans=0;
        for(int i=0;i<k;i++){
                ans+=countVowelStrings(n-1,k-i);
        }
        return dp[n][k]=ans;
        
    }
};