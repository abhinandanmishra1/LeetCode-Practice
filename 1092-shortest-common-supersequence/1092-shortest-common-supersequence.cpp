class Solution {
public:
    vector<vector<int>> dp;
    string shortestCommonSupersequence(string str1, string str2){
        dp.resize(str1.length()+1,vector<int>(str2.length()+1));
        dp[0][0]=0;
        for(int i=1;i<str2.length()+1;i++){
            dp[0][i]=dp[0][i-1]+1;
        }
        for(int i=1;i<str1.length()+1;i++){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int i=1;i<str1.length()+1;i++){
            for(int j=1;j<str2.length()+1;j++){
                if(str1[i-1]==str2[j-1]){
                     dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        // now last dp block is minimum length of scs
        // let's start traversing from back 
        int i=str1.length();
        int j=str2.length();
        string ans="";
        while(i>0 and j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }else if(dp[i-1][j]<dp[i][j-1]){
                ans.push_back(str1[i-1]);
                i--;
            }else{
                 ans.push_back(str2[j-1]);
                j--;
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};