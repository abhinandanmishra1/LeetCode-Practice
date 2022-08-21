class Solution {
public:
    bool checkPossibility(vector<int>&piles,int mid,int h){
        int count=0;
        for(int x:piles){
            count+=x%mid==0?x/mid:x/mid+1;
            if(count>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK=piles[0];
        for(int x:piles) maxK=max(maxK,x);
        
        int lo=1,hi=maxK;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(piles,mid,h)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};