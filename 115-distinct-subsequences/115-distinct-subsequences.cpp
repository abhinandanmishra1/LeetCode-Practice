class Solution {
public:
    string str,ttr;
    vector<vector<int>> dp;
    int findans(int n,int m){
        if(n<m) return 0;
        if(m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(str[n-1]==ttr[m-1]){
            return dp[n][m]=findans(n-1,m-1)+findans(n-1,m);
        }
        
        return dp[n][m]=findans(n-1,m);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        str=s;
        ttr=t;
        dp.resize(n+1,vector<int>(m+1,-1));
        
        return findans(n,m);
    }
};