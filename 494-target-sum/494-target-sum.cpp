class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        target=abs(target); /// because nums[i]>=0
        for(auto x:nums) {
            sum+=x;
        }
        if(sum<target or (sum+target)&1) return 0;
        sum+=target;
        sum/=2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        // starting from row 1 and column 0 because there can be zeros also
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};