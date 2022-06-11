class Solution {
public:
    int maximumLengthSubarraySum(vector<int> &nums,int target){
        int length=0;
        int start=0;
        int end=0;
        int sum=0;
        while(end<nums.size()){
            if(sum<target){
                sum+=nums[end++];
            }else if(sum==target){
                length=max(length,end-start);
                sum-=nums[start++];
            }else{
                sum-=nums[start++];
            }
        }
        
        while(sum>=target){
            if(sum>target){
                sum-=nums[start++];
            }else if(sum==target){
                length=max(length,end-start);
                sum-=nums[start++];
            }else{
                break;
            }
        }
        return length;
    }
    int minOperations(vector<int>& nums, int x) {
        int subArraySum=0; // after removing some element from left and right this sum is of remaining subarray
        for(auto x:nums) subArraySum+=x;
        // But x is removed from  it
        subArraySum-=x;
        // Now we have to only find the maximum length subarray whose sum is equal to subArraySum
        if(subArraySum<0) return -1;
        if(subArraySum==0) return nums.size();
        int maxLength=maximumLengthSubarraySum(nums,subArraySum);
        if(maxLength==0) return -1; // No subarray found
        return nums.size()-maxLength; 
    }
};