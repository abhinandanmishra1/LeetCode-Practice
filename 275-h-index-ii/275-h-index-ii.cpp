class Solution {
public:
    bool isPossible(vector<int> &arr,int &k){
        return (arr.end()-lower_bound(begin(arr),end(arr),k))<k;
    }
    int hIndex(vector<int>& citations) {
        int lo=0,hi=citations.back()+1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(citations,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo-1;
    }
};