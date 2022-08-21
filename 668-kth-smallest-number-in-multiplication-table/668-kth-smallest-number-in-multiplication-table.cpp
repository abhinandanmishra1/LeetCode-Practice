class Solution {
public:
    bool checkPossibility(int mid,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            int div=mid/i;
            if(mid<i) break;
            if(div<=n){
                count+=div;
            }else{
                count+=n;
            }
            if(count>=k) return true;
        }
        return false;
    }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(mid,m,n,k)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};