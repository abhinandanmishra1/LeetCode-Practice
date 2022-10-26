class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(),0);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and heights[i]>=heights[st.top()]){
                ans[st.top()]++;
                st.pop();
            }
            if(!st.empty()){
                ans[st.top()]++;
            }
            st.push(i);
        }
        return ans;
    }
};