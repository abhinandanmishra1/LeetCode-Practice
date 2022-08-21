class Solution {
public:
    bool checkPossibility(vector<int>&nums,int mid,int k){
        int count=0;
        
        for(int x:nums){
            if(x%mid==0)  count+=x/mid;
            else count+=x/mid+1;
        }
        return count<=k;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maxPossibleDivisor=nums[0];
        for(int x:nums) maxPossibleDivisor=max(maxPossibleDivisor,x);
        
        int lo=1,hi=maxPossibleDivisor;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(nums,mid,threshold)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};