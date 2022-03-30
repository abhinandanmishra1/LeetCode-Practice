class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        unordered_map<char, int> hg;
        for (int i = 0; i < n; i++){
            hg[S[i]] = i;
		}
        vector<int> ans;
        int s = 0, e = 0;
        for (int i = 0; i < n; i++) {
            e = max(e, hg[S[i]]);
            if (e == i) {
                ans.push_back(e-s+1);
                s = e+1;
            }
        } 
        return ans;
    }
};