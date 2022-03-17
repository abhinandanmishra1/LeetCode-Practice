class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        if(n==1) return 1;
        
        
        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                dp[i]=max(dp[i],dp[i+1]+1);
            }
        }
        for(int x:dp){
            ans+=x;
        }
        return ans;
    }
};