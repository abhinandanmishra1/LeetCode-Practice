class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxArea=0;
        st.push({-1,-1});
        for(int i=0;i<n;i++){
                while(!st.empty() and st.top().first>=heights[i]){
                    st.pop();
                }
                left[i]=st.top().second;
                st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        st.push({-1,n});
        
        for(int i=n-1;i>=0;i--){
                while(!st.empty() and st.top().first>=heights[i]){
                    st.pop();
                }
                right[i]=st.top().second;
                st.push({heights[i],i});
        }
        
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,(right[i]-left[i]-1)*heights[i]);
        }
        return maxArea;
    }
};