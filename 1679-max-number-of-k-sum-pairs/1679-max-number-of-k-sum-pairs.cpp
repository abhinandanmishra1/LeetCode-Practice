class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        int sum=0;
        for(auto x:mp){
            int num1=x.first;
            if(x.second==0) continue;
            if(num1*2==k){
                sum+=x.second/2;
                mp[x.first]=0;
            }
            else if(mp.find(k-num1)!=mp.end()){
                int ans=min(x.second,mp[k-num1]);
                sum+=ans;
                mp[x.first]=0;
                mp[k-num1]=0;
            }
        }
        return sum;
    }
};