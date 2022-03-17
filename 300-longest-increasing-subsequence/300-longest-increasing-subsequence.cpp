class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Traverse all the elements of the nums such that all the numbers behind
        // a given element which is smaller than it 
        // can be considered as ans
        // but the maximum value of all the smaller elements will be only taken into consideration
        int n=nums.size();
        vector<int> dp(n,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(nums[i]>nums[j]){
                    // finding smaller elements behind ith element
                    dp[i]=max(dp[i],dp[j]);
                    // and storing the maximum value out of all the smaller elements
                }
            }
            // as current value will also be added in the sequence
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};