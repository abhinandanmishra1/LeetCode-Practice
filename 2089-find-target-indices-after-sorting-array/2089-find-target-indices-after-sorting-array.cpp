class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int start=-1,end=-1;
        sort(begin(nums),nums.end());
        if(nums.size()==1){
            if(nums[0]==target) return {0};
            return {};
        }
        int low=-1,high=nums.size();
        while(low+1<high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]>=target){
                high=mid;
            }else{
                low=mid;
            }
        }
        
        start=high;
        
        low=-1,high=nums.size();
        while(low+1<high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]<=target){
                low=mid;
            }else{
                high=mid;
            } 
        }
        
        end=low;
        
        if(start==-1 or end==-1 or start==nums.size() or end==nums.size() or nums[start]!=target or nums[end]!=target) return {};
        
        vector<int> ans;
        for(;start<=end;start++) ans.push_back(start);
        return ans;
        
        
    }
};