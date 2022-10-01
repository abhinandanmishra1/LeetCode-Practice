class Solution {
public:
    vector<int> dp;
    Solution(){
        dp.resize(105,-1);
    }
    int numDecodings(string &s,int i=0) {
        if(i>s.length()) return 0;
        if(i==s.length()) return 1;
        if(dp[i]!=-1){ return dp[i]; }
        if(s[i]=='0') return dp[i]=0;
        int ans= numDecodings(s,i+1);
        
        if(i<s.length()-1 and ((s[i]=='1' and (s[i+1]>='0' and s[i+1]<='9')) or (s[i]=='2' and (s[i+1]>='0' and s[i+1]<='6')))){
            ans+=numDecodings(s,i+2);
        }
        
        return dp[i] = ans;
    }
};