class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long int ans=0;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> gc;
        for(int i=0;i<n;i++){
            if(gc.find(nums[i])==gc.end()){
                int g=gcd(nums[i],k);
                 gc[nums[i]]=g;
            }
            int g=gc[nums[i]];
            if(g!=1){
                mp[g].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%k==0){
                ans+=(n-i-1);
            }else{
                cout<<"FOR "<<nums[i]<<" ";
                int g=gc[nums[i]];
                
                for(int s=1;s*s<=g;s++){
                    if(g%s==0){
                        int f=k/s;
                        auto &arr=mp[f];
                        int kk=lower_bound(arr.begin(),arr.end(),i+1)-arr.begin();
                        ans+=(arr.size()-kk);
                        if(s*s!=g){
                            int ss=g/s;
                            int f=k/ss;
                            auto &arr=mp[f];
                            int kk=lower_bound(arr.begin(),arr.end(),i+1)-arr.begin();
                            ans+=(arr.size()-kk);
                        }
                    }
                }
                
                
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};