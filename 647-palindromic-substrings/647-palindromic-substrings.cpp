class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            ans++;
        }
        int k=0;
        while(++k<n){
            int i=0,j=k;
            
            while(i<n-k){
                if(s[i]==s[j] and (k==1 or dp[i+1][j-1])){
                    dp[i][j]=1;
                    ans++;
                }
                i++,j++;
            }
        }
        
        
        return ans;
    }
};