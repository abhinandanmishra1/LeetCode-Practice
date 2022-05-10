class Solution {
public:
    vector<vector<int>> combinationSum3(int n, int k,int start=1) {
        if(n==1){
            if(k>=start and k<=9){
                // cout<<k<<" \n";
                return {{k}};
            }
            return {{}};
        }
        vector<vector<int>> result;
        for(int i=start;i<=9;i++){
            int remaining=k-i;
            if(k<=0) break;
            auto computeAns=combinationSum3(n-1,remaining,i+1);
            if(computeAns.size()>0 and computeAns[0].size()>0){
                for(auto x:computeAns){
                    x.push_back(i);
                    result.push_back(x);
                }
            }
        }
        return result;
    }
};