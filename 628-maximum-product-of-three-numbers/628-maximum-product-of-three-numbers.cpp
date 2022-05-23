class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return max(nums[0]*nums[1]*nums.back(),nums.rbegin()[1]*nums.rbegin()[2]*nums.back());
    }
};