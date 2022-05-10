class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int maxArea=0;
        int i=0,j=height.size()-1;
        
        while(i<j){
            maxArea=max(maxArea,(j-i)*(min(height[j],height[i])));
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};