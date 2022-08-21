class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int lo=0,hi=nums.size();
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi=mid; // answer is less than hi
            }else{
                lo=mid+1; // next position is good to insert 
            }
        }
        
        return lo;
    }
};