class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
            vector<int> buckets(10001,0);
            int maxer=0;
            for (int num : nums) {
                buckets[num] += num;
                maxer=max(maxer,num);
            }
            vector<int> dp(maxer+1);
            dp[0] = buckets[0];
            dp[1] = buckets[1];
            for (int i = 2; i <= maxer; i++) {
                dp[i] = max(buckets[i] + dp[i - 2], dp[i - 1]);
            }
            return dp[maxer];
    }
};
