class Solution {
public:
    int divide(int divide, int divis) {
        int isNegative=(divide<0 ^ divis<0);
        long int ans=0;
        long int dividend=abs(divide);
        long int divisor=abs(divis);
        while(dividend>=divisor){
            long int val=divisor;
            long int multiple=1;
            while(2*val<=dividend){
                val*=2;
                multiple*=2;
            }
            ans+=multiple;
            dividend-=val;
        }
        if(ans>INT_MAX){
            return isNegative?INT_MIN:INT_MAX;
        }
        return isNegative?-ans:ans;
    }
};