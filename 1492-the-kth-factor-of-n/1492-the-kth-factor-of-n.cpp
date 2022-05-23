class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                factors.push_back(i);
                if(i*i!=n){
                    factors.push_back(n/i);
                }
            }
        }
        sort(begin(factors),end(factors));
        k--;
        return k<factors.size()?factors[k]:-1;
    }
};