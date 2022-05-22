class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int ma=INT_MAX;
        for(auto x:nums){
            ma=min(ma,x);
        }
        
        for(auto x:nums){
            ans+=x-ma;
        }
        return ans;
    }
};