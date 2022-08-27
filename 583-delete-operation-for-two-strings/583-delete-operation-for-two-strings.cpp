class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string &s1,string &s2,int n,int m){
        if(n<=0 or m<=0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]=1+lcs(s1,s2,n-1,m-1);
        }
        
        return dp[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
    int minDistance(string &s1, string &s2) {
        int n=s1.length(),m=s2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return m+n-2*lcs(s1,s2,n,m);
    }
};