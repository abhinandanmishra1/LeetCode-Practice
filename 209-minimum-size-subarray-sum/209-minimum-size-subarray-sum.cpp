class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int sum=0;
        int start=0,end=0;
        
        while(end<nums.size()){
            sum+=nums[end++];
            while(sum>=target){
                ans = min(ans,end-start);
                sum-=nums[start++];
            }
        }
        
        return ans==INT_MAX?0:ans;
    }
};