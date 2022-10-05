class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int start=0,end=0;
        while(end<nums.size()){
            if(end>k){
                mp[nums[start++]]--;
            }
            if(mp[nums[end]]){
                return true;
            }
            mp[nums[end++]]++;
        }
        return false;
    }
};