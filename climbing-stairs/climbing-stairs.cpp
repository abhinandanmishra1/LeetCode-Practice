class Solution {
public:
    unordered_map<int,int> dp;
    int climbStairs(int n) {
        if(n==1 or n==2) return n;
        if(dp.find(n)!=dp.end()) return dp[n];
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};