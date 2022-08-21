class Solution {
public:
    bool checkPossibility(vector<int>&arr,int hr,int count,int k){
        int cnt=0;
        int curr=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=hr){
                curr++;
            }else{
                curr=0;
            }
            if(curr==k){
                cnt++;
                curr=0;
            }
        }
        return cnt>=count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<m*k) return -1;
        
        int maxAns=bloomDay[0];
        for(int x:bloomDay){
            maxAns=max(maxAns,x);
        }
        
        int lo=1,hi=maxAns;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(bloomDay,mid,m,k)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};