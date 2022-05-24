class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int ans=0;
        int open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            // if open is less then keep adding 
            // if open is greater than close then there is chance that 
            // close will increase and become equal to open
            // if close is greater at some point that means this 
            // substring is not valid now intialize with open=close=0
            // if both are equal --> store max(ans,open+close) 
            if(open==close) ans=max(ans,open+close);
            else if(close>open) open=close=0;
        }
        open=close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            // if close is less then keep adding 
            // if close is greater than open then there is chance that 
            // open will increase and become equal to close
            // if open is greater at some point that means this 
            // substring is not valid now intialize with open=close=0
            // if both are equal --> store ans=max(ans,open+close) 
            if(open==close) ans=max(ans,open+close);
            else if(close<open) open=close=0;
        }
        return ans;
    }
};