class Solution {
public:
   
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> dp(n);
        int m=0,ind=0;
        for(int i=0;i<n;i++){
            dp[i].push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[j].size()+1>dp[i].size()){
                        dp[i]=dp[j];
                        dp[i].push_back(nums[i]);
                    }
                }
            }
            if(dp[i].size()>m){
                m=dp[i].size();
                ind=i;
            }
        }
        
        return dp[ind];
    }
};
