class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x:nums) mp[x]++;
        vector<vector<int>> store;
        for(auto x:mp){
            store.push_back({x.second,x.first});
        }
        sort(store.rbegin(),store.rend());
        vector<int> ans;
        for(auto x:store){
            if(k==0) break;
            ans.push_back(x[1]);
            k--;
        }
        return ans;
    }
};