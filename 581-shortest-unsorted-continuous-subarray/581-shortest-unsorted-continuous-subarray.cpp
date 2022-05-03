class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     vector<int> arr=nums;
     sort(begin(arr),end(arr));
     int i=0;
     while(i<nums.size() and arr[i]==nums[i]){
         i++;
     }
     if(i==nums.size()) return 0;
     int j=nums.size()-1;
     while(j>=0 and nums[j]==arr[j]) j--;
     return j-i+1;
    }
};