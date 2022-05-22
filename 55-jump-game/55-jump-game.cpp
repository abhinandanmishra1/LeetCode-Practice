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
/*
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
      if(prevLargestRange.top()>=nums.size()-1) return true; // Handling the case where size==1
        return false;
    }
};

*/

// Approach - 3
// If we think of moving from backward (n-2)th place and keep checking whether we can reach 
// to last position from the current position or not 
// if yes then change last to currentPosition and keep checking untill i>=0

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            int currentRange=i+nums[i];
            if(currentRange>=last){
                last=i;
                // changing it to i to check now can we reach to this i or not
            }
        }
       return last==0;
    }
};
*/


// Approach 4

class Solution {
public:
    // If i store the maximum range from current index
    // and iterate only upto the maximum range
    // update the maximumRange if currentRange is maximum
    bool canJump(vector<int>& nums) {
        int maximumRange=0; // initially Range is 0 (before i=0)
        int i=0;
        while(i<=maximumRange){
            int currentRange=i+nums[i];
            if(currentRange>=nums.size()-1) return true;
            maximumRange=max(maximumRange,currentRange);
            i++;
        }
        return false;
    }
};
