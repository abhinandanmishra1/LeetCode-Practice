class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int i=0;
        for(int curr:nums){
            int other=target-curr;
            if(mp.find(other)!=mp.end()){
                return {mp[other],i};
            }
            mp[curr]=i++;
        }
        
        return {};
    }
};