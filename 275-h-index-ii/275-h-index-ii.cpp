class Solution {
public:
    bool checkPossibility(vector<int>&arr,int k){
        int count=0;
        for(int &x:arr){
            count+=x>=k;
        }
        return count<k;
    }
    int hIndex(vector<int>& citations) {
        int maxPossible=citations.back();

        int lo=0,hi=maxPossible+1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(citations,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo-1;
    }
};