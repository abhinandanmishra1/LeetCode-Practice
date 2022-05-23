class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        int prevPowerof2=1;
        for(int i=1;i<=n;i++){
            if(!(i&(i-1))){
                ans[i]=1;
                prevPowerof2=i;
            }else{
                ans[i]=1+ans[i-prevPowerof2];
            }
        }
        return ans;
    }
};