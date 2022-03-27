class Solution {
public:
    static bool cmp(pair<vector<int>,vector<int>> &p1,pair<vector<int>,vector<int>> &p2){
        if(p1.second[1]!=p2.second[1]) return p1.second[1]<p2.second[1];
        return p1.second[0]<p2.second[0];
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<vector<int>,vector<int>>> store;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(auto x:mat[i]){
                sum+=x;
            }
            store.push_back({mat[i],{i,sum}});
        }
        sort(store.begin(),store.end(),cmp);
        vector<int> ans;
        
        for(auto x:store){
            ans.push_back(x.second[0]);
            k--;
            if(k==0) break;
        }
        return ans;
        
    }
};