class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lo=-1,hi=nums.size()-1;
        
        while(lo+1<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>=target){
                hi=mid;
            }else{
                lo=mid;
            }
        }
        
        int start=hi;
        if(start==-1 or nums[start]!=target){
            start=-1;
        }
        lo=0,hi=nums.size();
        while(lo+1<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=target){
                lo=mid;
            }else{
                hi=mid;
            }
        }
        int end=lo;
        if(end==nums.size() or nums[end]!=target){
            end=-1;
        }
        
        return {start,end};
    }
};