class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        int start=-1,end=x/2+1;
        int ans=0;
        while(start+1<end){
            long long int mid=start+(end-start)/2;
            if(mid*mid<=x){
                start=mid;
            }else{
                end=mid;
            }
        }
        return start;
    }
};