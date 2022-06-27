class Solution {
public:
    int minPartitions(string n) {
        char ans='0';
        for(auto x:n){
            ans=max(ans,x);
        }
        return ans-'0';
    }
};