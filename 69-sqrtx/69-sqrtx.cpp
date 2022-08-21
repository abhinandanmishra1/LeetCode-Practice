class Solution {
public:
    int mySqrt(int x) {
        long int lo=0,hi=(long)x+1;
        
        while(lo<hi){
            long long int mid=lo+(hi-lo)/2;
            if(mid*mid<=x){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return (int)lo-1;
    }
};