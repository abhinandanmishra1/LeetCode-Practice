class Solution {
public:
    string str;
    int n;
    vector<vector<int>> dp;
    int lps(int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str[i]==str[j]){
            return dp[i][j]=lps(1+i,-1+j)+2;
        }
        
        return dp[i][j]=max(lps(1+i,j),lps(i,-1+j));
    }
    int longestPalindromeSubseq(string s) {
        str=s;
        n=s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return lps(0,n-1);
        
    }
};