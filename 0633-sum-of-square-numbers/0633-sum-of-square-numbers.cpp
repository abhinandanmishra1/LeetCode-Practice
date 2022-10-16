class Solution {
public:
    bool judgeSquareSum(int c) {
        int maxVal=sqrt(c);
        for(int i=0;i<=maxVal;i++){
            int other=c-i*i;
            int otherSqrt=sqrt(other);
            if(otherSqrt*otherSqrt==other) return true;
        }
        return false;
    }
};