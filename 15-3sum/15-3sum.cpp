class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort first 
        //  Simple method to do this is to bind one element 
        // then simply take two element after that element and end element 
        // check if sum==0 if 0 add it to ans 
        // then increase start index up to which it is same with the previous value
        // that is 4 4 4 4 5 is array then start will go to 5th position 
        // same thing for last element also
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            // removing duplicates from very beginning
            
            int j=i+1,k=n-1;
            
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int val=nums[j];
                    while(j<k and nums[j]==val) j++; 
                    // remove duplicate elements from start
                    
                    val=nums[k];
                    
                    while(k>j and nums[k]==val) k--; 
                    // remove duplicate elements from end
                }else if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};