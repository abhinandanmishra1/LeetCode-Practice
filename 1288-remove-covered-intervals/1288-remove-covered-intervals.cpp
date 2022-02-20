class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        
        int n=arr.size();
        int count=0;
        vector<int> removed(n,false);
        for(int i=0;i<n;i++){
            if(removed[i]) continue;
            auto & brr=arr[i];
            for(int j=0;j<n;j++){
                if(removed[j]) continue;
                if(i==j) continue;
                auto& crr=arr[j];
                if(brr[0]<=crr[0] and brr[1]>=crr[1]){
                    count++;
                    removed[j]=true;
                }
            }
        }
        return n-count;
    }
};