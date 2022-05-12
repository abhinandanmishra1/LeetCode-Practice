class Solution {
public:
    vector<vector<int>> res;
    vector<bool> visited;
    void dfs(vector<int>&nums,vector<int>&store){
        if(store.size()==nums.size()){
            res.push_back(store);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 and visited[i-1] and nums[i]==nums[i-1]) {
                // if [1 1 1 1 1 2 3 4]
                // then entry of 1 will start from second occurrence of 1
                // [1 1 2]-> if we choose second 1 first then only first 1 will be selected
                continue;
            }
            if(!visited[i]){
                visited[i]=true;
                store.push_back(nums[i]);
                dfs(nums,store);
                store.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited.resize(nums.size(),false);
        vector<int> store;
        sort(begin(nums),end(nums));
        // do sorting to remove duplicates from the result
        dfs(nums,store);
        return res;
    }
};