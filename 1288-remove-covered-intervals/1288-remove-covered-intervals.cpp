class Solution {
public:
    static bool cmp(vector<int> &a,vector<int>&b){
        int diff1=a[1]-a[0];
        int diff2=b[1]-b[0];
        if(diff1!=diff2){
            return diff1<diff2;
        }
        return a[0]!=b[0]?a[0]<b[0]:a[1]<b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int n=arr.size();
        int count=0;
        vector<int> removed(n,false);
        for(int i=0;i<n;i++){
            if(removed[i]) continue;
            auto brr=arr[i];
            for(int j=0;j<n;j++){
                if(removed[j]) continue;
                if(i==j) continue;
                auto crr=arr[j];
                if(brr[0]<=crr[0] and brr[1]>=crr[1]){
                    count++;
                    removed[j]=true;
                }
            }
        }
        return n-count;
    }
};