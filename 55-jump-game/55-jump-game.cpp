// Approach 1
/*
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
*/

// Approach 2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // If i add the indexes i to each nums[i] 
        priority_queue<int> prevLargestRange;
        prevLargestRange.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(prevLargestRange.top()>=nums.size()-1) return true;
            if(prevLargestRange.top()>=i){
                 int currentRange=nums[i]+i;
                 prevLargestRange.push(currentRange);
            }else{
                 return false;
            }
        }
        if(prevLargestRange.top()>=nums.size()-1) return true;
        return false;
    }
};