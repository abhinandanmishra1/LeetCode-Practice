class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Binary search implementation
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int ii=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ii]=nums[i];
            }
        }
        return ans.size();
    }
};