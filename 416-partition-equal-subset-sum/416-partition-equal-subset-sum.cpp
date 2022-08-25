class Solution {
public:
    bool isSubsetSum(vector<int>&nums,int sum){
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1])
                dp[i][j] = dp[i][j] or dp[i-1][j-nums[i-1]];
            }
            if(dp[i][sum]){
                return true;
            }
        }
        
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &x:nums){
            sum+=x;
        }
        if(sum&1) return false;
        
        sum=sum/2;
        
        return isSubsetSum(nums,sum);
    }
};