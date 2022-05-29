class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> store=nums;
        sort(rbegin(nums),rend(nums));
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<store.size();i++){
            if(mp[store[i]]>0){
                ans.push_back(store[i]);
                mp[store[i]]--;
            }
        }
        return ans;
    }
};