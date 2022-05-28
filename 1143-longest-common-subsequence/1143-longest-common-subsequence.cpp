class Solution {
public:
    vector<vector<int>> dp;
int lcs(string &s1,string &s2,int n,int m){
    if(m==0 or n==0) return 0;
    if(s1[n-1]==s2[m-1]){
        dp[n][m]=1+lcs(s1,s2,n-1,m-1);
    }
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]=max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
}
    int longestCommonSubsequence(string A, string B) {
         dp.resize(A.length()+1,vector<int>(B.length()+1,-1));
    return lcs(A,B,A.length(),B.length());
    }
};