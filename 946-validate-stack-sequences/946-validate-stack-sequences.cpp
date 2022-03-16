class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int i=0,j=0;
        vector<int> store;
        while(i<n){
            if(!st.empty() and st.top()==popped[j]){
                store.push_back(st.top());
                st.pop();
                j++;
            }else{
                st.push(pushed[i]);
                i++;
            }
            
        }
        while(!st.empty()){
            store.push_back(st.top());
            st.pop();
        }
        // for(auto x:store) cout<<x<<" "; 
        return store==popped;
    }
};