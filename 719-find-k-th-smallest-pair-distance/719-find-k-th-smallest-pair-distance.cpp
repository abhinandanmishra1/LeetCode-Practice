class Solution {
public:
    int checkPossibility(vector<int>&nums,int mid,int k){
        int i=0,j=0;
        int count=0;
        int n=nums.size();
        while(i<n or j<n){
            while(j<n and nums[j]-nums[i]<=mid) j++;
            count+=j-i-1;    
            i++;
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int lo=0,hi=nums.back()-nums[0];
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            
            if(checkPossibility(nums,mid,k)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        
        return lo;
    }
};