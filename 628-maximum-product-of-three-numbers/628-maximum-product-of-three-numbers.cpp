class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        return max(nums[0]*nums[1]*nums[2],nums[0]*nums.back()*nums[nums.size()-2]);
    }
};