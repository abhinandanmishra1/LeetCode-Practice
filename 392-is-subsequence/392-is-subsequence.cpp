class Solution {
public:
    vector<vector<int>> dp;
    Solution(){
        dp.resize(101,vector<int>(10001,-1));
    }
    bool isSubsequence(string &s, string &t,int i=0,int j=0) {
        if(i==s.length()) return true;
        if(j==t.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=isSubsequence(s,t,i+1,j+1);
        }
        return dp[i][j]=isSubsequence(s,t,i,j+1);
    }
};