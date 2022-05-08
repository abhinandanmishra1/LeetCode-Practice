class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=1;
        int previousMinimum=prices[0];
        int ans=0;
        while(i<prices.size()){
            if(prices[i]>prices[i-1]) i++;
            else{
                ans+=prices[i-1]-previousMinimum;
                previousMinimum=prices[i];
                i++;
            }
        }
        ans+=prices[i-1]-previousMinimum;
        return ans;
    }
};