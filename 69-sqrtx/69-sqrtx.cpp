class Solution {
public:
    int mySqrt(int x) {
        long int lo=0,hi=(long)x+1;
        
        while(lo<hi){
            long long int mid=lo+(hi-lo)/2;
            if(mid*mid>x){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return (int)lo-1;
    }
};