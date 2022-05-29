class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),[](int &a,int &b){
            int aCount=__builtin_popcount(a);
            int bCount=__builtin_popcount(b);
            if(aCount==bCount) return a<b;
            return aCount<bCount;
        });
            return arr;
    }
};