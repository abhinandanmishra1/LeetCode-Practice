class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> ans;
        int i=0;
        for(auto x:nums){
            if(ans.size()==0) ans.push_back(nums[i++]);
            else{
                ans.push_back(ans[i-1]+nums[i++]);
            }
        }
        return ans;
    }
};