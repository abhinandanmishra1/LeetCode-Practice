class Solution {
public:
    int countBinarySubstrings(string s) {
        int i=0;
        int prev=0;
        int ans=0;
        while(i<s.length()){
            int cnt=0;
            int j=i;
            while(j<s.length() and s[j]==s[i]) j++,cnt++;
            ans+=min(cnt,prev);
            prev=cnt;
            i=j;
        }
        return ans;
    }
};