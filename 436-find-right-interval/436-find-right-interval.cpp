class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> store;
        
        for(int i=0;i<intervals.size();i++){
            store.push_back({intervals[i][0],i});
        }
        sort(store.begin(),store.end());
        
        vector<int> res;
        for(auto x:intervals){
            
            int start=-1,end=store.size();
            while(start+1<end){
                int mid=start+(end-start)/2;
                if(store[mid][0]>=x[1]){
                    end=mid;
                }else{
                    start=mid;
                }
            }
            if(end==store.size()){
                res.push_back(-1);
            }else{
                res.push_back(store[end][1]);
            }
        }
        return res;
    }
};