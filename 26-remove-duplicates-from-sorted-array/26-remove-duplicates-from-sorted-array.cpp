class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(1){
            int k=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(k==nums.size()) return i+1;
            nums[i+1]=nums[k];
            i++;
        }
        return 0;
    }
};

