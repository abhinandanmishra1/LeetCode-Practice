class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int previousMinimum=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>previousMinimum){
                ans=max(ans,prices[i]-previousMinimum);
            }
            previousMinimum=min(previousMinimum,prices[i]);
        }
        return ans;
    }
};