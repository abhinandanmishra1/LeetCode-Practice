class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxLen=1;
        int start=0;
        
        for(int i=0;i<n-1;i++){
            dp[i][i]=1;
            dp[i][i+1]=(s[i]==s[i+1]);
            if(dp[i][i+1] and maxLen==1){
                maxLen=2;
                start=i;
            }
        }
        dp[n-1][n-1]=1;
        for(int k=2;k<n;k++){ 
                int i=0,j=k;
                while(i<n-k and j<n){
                        dp[i][j]=(s[i]==s[j] and dp[i+1][j-1]);
                        int len=j-i+1;
                        if(dp[i][j] and len>maxLen){
                            maxLen=len;
                            start=i;
                        }
                    i++,j++;
                }   
            }
        
        return s.substr(start,maxLen);
        
    }
};