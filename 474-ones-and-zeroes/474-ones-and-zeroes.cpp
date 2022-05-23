class Solution {
public:
    
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        // ["10","0001","111001","1","0"]
        // [{1,1},{3,1},{2,4},{0,1},{1,0}]   (0th position -> 0) (1st pos-> 1)
        int size=strs.size();
        vector<vector<int>> store;
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(size+1,0)));
        
        // this 3d vector signifies that -> dp[i][j][k]
        // How many strings can be made for maximum of i zeroes , j ones and using k strings
        int k=1;
        for(auto str:strs){
            int zero=0,one=0;
            for(auto ch:str){
                zero+=(ch=='0');
                one+=(ch=='1');
            }
            // whether this K should be included or not
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(i>=zero and j>=one)
                        dp[i][j][k]=max(dp[i][j][k-1],dp[i-zero][j-one][k-1]+1);
                    else
                        dp[i][j][k]=dp[i][j][k-1];
                }
            }
            k++;
        }
        return dp[m][n][size];
        
    }
};