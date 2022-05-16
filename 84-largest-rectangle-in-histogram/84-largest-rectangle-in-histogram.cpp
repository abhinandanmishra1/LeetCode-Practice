class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea=0;
        heights.push_back(0); // so that the logic can work for last Element also
        // Like for [2,4] st will become {2,4} but maxArea will be 0 
        // so if 0 will be last then the while loop will run and ans will be stored
        for(int i=0;i<heights.size();i++){
            while(!st.empty() and st.top().first>=heights[i]){
                int height=st.top().first;
                st.pop();
                int prevInd=st.empty()?-1:st.top().second;
                int currArea=height*(i-prevInd-1);
                maxArea=max(currArea,maxArea);
            }
            
            // We're checking backwars untill we get an element smaller than currEle
            // or stack becomes empty
            st.push({heights[i],i});
        }
        return maxArea;
    }
};

/*
    Dry run of Algorithm
    Arr = [2,1,5,6,2,3]
    
    i=0 
    st.push({2,0});
    
    i=1
    check if previous element is greater or equal-> yes
    that means this i can be end of previous element 
    Find start index for that element and then find width and answer will be stored
*/