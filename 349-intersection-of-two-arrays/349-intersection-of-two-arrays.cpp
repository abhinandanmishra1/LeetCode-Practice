class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto x:nums1) mp1[x]++;
        for(auto x:nums2) mp2[x]++;
        
        vector<int> res;
        for(auto x:mp1){
            if(mp2.find(x.first)!=mp2.end()){
                res.push_back(x.first);
            }
        }
        return res;
    }
};