class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        if(num&1){
            num--;
            return num==0?1:2+numberOfSteps(num/2);
        }
        return 1+numberOfSteps(num/2);
    }
};