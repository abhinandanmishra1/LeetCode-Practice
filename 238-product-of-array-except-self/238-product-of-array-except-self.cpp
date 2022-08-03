class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left=1;
        int right=1;
        vector<int> ans(nums.size(),1);
        for(int i=0;i<nums.size();i++){ 
            ans[i]*=left;
            ans[ans.size()-1-i]*=right;
            left*=nums[i];
            right*=nums[nums.size()-1-i];  
        }
        return ans;
    }
};