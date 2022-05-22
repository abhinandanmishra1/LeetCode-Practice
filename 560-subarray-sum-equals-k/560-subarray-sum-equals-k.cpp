class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prevSums;
        prevSums[0]++; 
        int ans=0;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            if(prevSums.find(sum-k)!=prevSums.end()){
                ans+=prevSums[sum-k]; // as much time the sum-k has appeared previously
            }
            prevSums[sum]++;
        }
        return ans;
    }
};