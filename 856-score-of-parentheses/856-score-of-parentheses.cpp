class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        stack<int> st;
        st.push(0);
        for(auto x:s){
            if(x=='('){
                st.push(0);
            }else{
                int t=st.top();
                st.pop();
                if(t>0) t*=2;
                else t=1;
                int k=st.top()+t;
                st.pop();
                st.push(k);
            }
        }
        return st.top();
    }
};