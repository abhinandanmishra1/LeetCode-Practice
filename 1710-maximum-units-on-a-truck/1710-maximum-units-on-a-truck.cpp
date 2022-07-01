class Solution {
public:
    static bool cmp(vector<int>&A,vector<int>&B){
        return A[1]>B[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(auto x:boxTypes){
            if(x[0]>=truckSize){
                ans+=truckSize*x[1];
                return ans;
            }else{
                ans+=x[0]*x[1];
                truckSize-=x[0];
            }
        }
        return ans;
    }
};