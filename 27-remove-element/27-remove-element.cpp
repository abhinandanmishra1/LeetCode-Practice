class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        int i=0,j=n-1;
        while(i<j){
            if(nums[j]==val){
                j--;
            }else{
                if(nums[i]==val){
                    swap(nums[i],nums[j]);
                    j--;
                }else{
                    i++;
                }
            }
        }
        if(nums[i]==val) return i;
        return i+1;
    }
};