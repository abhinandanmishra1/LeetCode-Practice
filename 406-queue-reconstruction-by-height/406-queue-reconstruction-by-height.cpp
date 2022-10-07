class Solution {
public:

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size());
        sort(begin(people),end(people));
        for(auto &x:people){
            int cnt=x[1];
            for(int i=0;i<ans.size();i++){
                if(ans[i].size()==0 and cnt==0){
                    ans[i]=x;
                    break;
                }
                if(ans[i].size()==0 or ans[i][0]>=x[0] ) cnt--;
            }
        }
        return ans;
    }
};