class Solution {
public:
    int mySqrt(int x) {
        long int start=-1,end=(long)x+1;
        while(start+1<end){
            long long int mid=start+(end-start)/2;
            if(mid*mid<=x){
                start=mid;
            }else{
                end=mid;
            }
        }
        return (int)start;
    }
};