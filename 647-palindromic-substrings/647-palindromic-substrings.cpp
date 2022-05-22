class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int k=0;
        while(++k<n){
            int i=0,j=k;
            
            while(i<n-k){
                if(s[i]==s[j] and (k==1 or dp[i+1][j-1])){
                    dp[i][j]=1;
                }
                i++,j++;
            }
        }
        
        int ans=0;
        for(auto x:dp){
            for(auto y:x) ans+=y;
        }
        return ans;
    }
};