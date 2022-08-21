class Solution {
public:
    bool check(vector<int>&weights,int days,int cap){
        int ans=1,sum=0;
        
        for(int i=0;i<weights.size();i++){
            if(weights[i]>cap) return false;
            if(sum+weights[i]<=cap){
                sum+=weights[i];
            }else{
                sum=weights[i];
                ans++;
                if(ans>days) return false;
            }
        }
        return ans<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0;
        for(auto x:weights) maxCapacity+=x;
        int lo=1,hi=maxCapacity;
        
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            
            if(check(weights,days,mid)){
                hi=mid;
            }else{
                lo=mid+1;
            }
            // cout<<lo<<" "<<hi<<endl;
        }
        
        return lo;
    }
};