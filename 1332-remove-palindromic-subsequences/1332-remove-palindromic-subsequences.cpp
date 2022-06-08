class Solution {
public:
    int removePalindromeSub(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(rev==s) return 1;
        return 2;
    }
};