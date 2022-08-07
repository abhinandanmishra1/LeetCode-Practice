class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long int start=-1,end=num/2+4;
        while(start+1<end){
            long long int mid=start+(end-start)/2;
            if(mid*mid<=num){
                start=mid;
            }else{
                end=mid;
            }
        }
        return start*start==num;
    }
};