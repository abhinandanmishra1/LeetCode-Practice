class Solution {
public:
    bool judgeSquareSum(int c) {
        int maxVal=sqrt(c);
        long long int i=0,j=maxVal;
        while(i<=j){
            long long int val=i*i+j*j;
            if(val==c) return true;
            if(val>c){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};