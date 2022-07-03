class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int prev=nums[1]-nums[0];
        int ans=prev!=0?2:1;
        
        for(int i=2;i<nums.size();i++){
            int curr=nums[i]-nums[i-1];
            if((prev>=0 and curr<0) or (prev<=0 and curr>0)){
                ans++;
                prev=curr;
            }
        }
        return ans;
    }
};