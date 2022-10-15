class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int minDiff=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            minDiff=min(minDiff,arr[i+1]-arr[i]);
        }
        
        set<vector<int>> st;
        for(int i=0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i])==minDiff){
                st.insert({arr[i],arr[i+1]});
            }
        }
        vector<vector<int>> ans;
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};