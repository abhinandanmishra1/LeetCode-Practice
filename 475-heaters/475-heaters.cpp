class Solution {
public:
    bool checkPossibility(vector<int>& houses, vector<int>& heaters,int mid){
       int lo=houses[0],hi=houses.back();
       for(auto &x:heaters){
           int start=max(x-mid,lo);
           int end=min(x+mid,hi);
           if(start>lo){
               return false;
           }
           auto it=upper_bound(houses.begin(),houses.end(),end);
           if(it==houses.end()) return true;
           lo=*it;
           if(end==hi){
               return true;
           }
       } 
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(begin(houses),end(houses));
        sort(begin(heaters),end(heaters));
        int lo=0,hi=max(houses.back(),heaters.back());
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(checkPossibility(houses,heaters,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};