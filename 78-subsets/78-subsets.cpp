class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums,int i=0) {
        if(i==nums.size()) return {{}};
        auto ans=subsets(nums,i+1);
        int size=ans.size();
        for(int j=0;j<size;j++){
            ans[j].push_back(nums[i]);
            ans.push_back(ans[j]);
            ans[j].pop_back();
        }
        return ans;  
    }
};