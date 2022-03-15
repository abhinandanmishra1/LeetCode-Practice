class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        stack<char> st;
        int n=s.length();
        int count=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                ans.push_back('(');
                st.push('(');
            }else if( s[i]==')'){
                if(!st.empty() and st.top()=='('){
                    ans.push_back(')');
                    st.pop();
                }
            }else{
                ans+=s[i];
            }
            i++;
        }
        reverse(ans.begin(),ans.end());
        s=ans;
        ans="";
        n=s.length();
        i=0;
    
            while(i<n){
            if(s[i]=='(' and !st.empty()){
                st.pop();
            }else{
                ans+=s[i];
            }
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};