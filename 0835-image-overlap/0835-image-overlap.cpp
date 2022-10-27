class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        
        vector<vector<int>> st1,st2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]){
                    st1.push_back({i,j});
                }
                if(img2[i][j]){
                    st2.push_back({i,j});
                }
            }
        }
        
        unordered_map<string,int> count;
        for(auto x:st1){
            for(auto y:st2){
                string s=to_string(x[0]-y[0])+"#"+to_string(x[1]-y[1]);
                count[s]++;
            }
        }
        
        int ans=0;
        for(auto x:count){
            ans=max(ans,x.second);
        }
        return ans;
    }
};