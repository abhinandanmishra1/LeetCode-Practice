class Solution {
public:
    bool condition(long long int k,int n){
        long int ans=k&1?k*((k+1)/2):(k/2)*(k+1);
        return ans<=n;
    }
    int arrangeCoins(int n) {
       long long int lo=1,hi=(long long)n+1;
       // lo=1 minimum answer possible
       // hi=n+1 minimum answer impossible
       // ans<n+1
        while(lo+1<hi){
            long long int mid=lo+(hi-lo)/2;
            if(condition(mid,n)){
                lo=mid;
            }else{
                hi=mid;
            }
        }
        
        return lo;
    }
};