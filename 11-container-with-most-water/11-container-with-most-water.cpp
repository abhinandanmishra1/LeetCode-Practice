class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int currentArea=(j-i)*min(height[i],height[j]);
            ans=max(ans,currentArea);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};