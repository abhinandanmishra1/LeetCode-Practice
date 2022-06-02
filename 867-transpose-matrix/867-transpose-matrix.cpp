class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix[0].size());
        
            for(int j=0;j<matrix[0].size();j++){
                for(int i=0;i<matrix.size();i++){
                    ans[j].push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};