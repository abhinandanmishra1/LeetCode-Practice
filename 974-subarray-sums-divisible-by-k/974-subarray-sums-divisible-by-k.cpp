class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            // cout<<sum<<" "<<sum%k<<endl;
            if(sum<0){
                sum=sum%k;
                sum+=k;
            }
            mp[sum%k]++;
        }
        
        int ans=mp[0];
        for(auto [x,y]:mp){
            ans+=(y*(y-1)/2);
        }
        return ans;
    }
};