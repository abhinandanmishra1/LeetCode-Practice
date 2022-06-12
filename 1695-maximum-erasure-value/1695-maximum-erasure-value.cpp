class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        
        unordered_map<int,int> mp;
        int ans=0;
        int prev=1;
        for(int i=1;i<=n;i++){
            if(mp[nums[i-1]]>=prev){
                ans=max(ans,prefix[i-1]-prefix[prev-1]);
                prev=mp[nums[i-1]]+1;
                mp[nums[i-1]]=i;
                // cout<<i<<":"<<prefix[i-1]<<" ";
            }else{
                mp[nums[i-1]]=i;
            }
        }
        cout<<endl;
        ans=max(ans,prefix[n]-prefix[prev-1]);
        return ans;
    }
};