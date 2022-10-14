class Solution {
public:
    vector<int> dp;
    int getMaxAns(vector<int>& prices,int i,int prev=-1){
        if(i>=prices.size()) return 0;
        if(dp[i]!=-1 and prev==-1){
            return dp[i];
        }
        if(prev==-1){
            return dp[i]=max(getMaxAns(prices,i+1,-1),getMaxAns(prices,i+1,prices[i]));
        }
        int ans = 0;
        if(prices[i]>prev){
            ans = prices[i] - prev + getMaxAns(prices, i+2, -1);
        }
        
        return max(ans,getMaxAns(prices,i+1,prev));
        
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),-1);
        return getMaxAns(prices,0,-1);
    }
};