class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+2,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++){
            int leftSum=prefix[i-1];
            int rightSum=prefix[n]-prefix[i];
            
            if(leftSum==rightSum) return i-1;
        }
        return -1;
    }
};