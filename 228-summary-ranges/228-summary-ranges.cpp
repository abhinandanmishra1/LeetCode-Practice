class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i=0;
        int n=nums.size();
        while(i<n){
            string add=to_string(nums[i]);
            
            int x=nums[i];
            i++;
            bool flag=true;
            while(i<n and nums[i]==(nums[i-1]+1)){
                flag=false;
                i++;
            }
            if(!flag){
               add+="->";
               add+=to_string(nums[i-1]); 
            }
            ans.push_back(add);    
        }
        
        return ans;
    }
};