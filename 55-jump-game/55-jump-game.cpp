// Approach 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        visited[0]=true;
        for(int i=0;i<nums.size();i++){
            if(visited[i]){
                int end=i+nums[i];
                if(end>=nums.size()-1) return true;
                for(int j=i+1;j<=end;j++) visited[j]=true;
            }
        }
        return false;
    }
};