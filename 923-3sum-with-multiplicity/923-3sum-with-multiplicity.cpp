class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod=1e9+7;
        int n=arr.size();
        long int ans=0;
        for(int i=0;i<n;i++){
            vector<int> store(101,0);
            for(int j=i+1;j<n;j++){
                int rem=target-arr[i]-arr[j];
                if(rem>=0 and rem<=100 and store[rem]>0){
                    ans+=store[rem];
                    ans%=mod;
                }
                store[arr[j]]++;
            }
        }
        
        return (int)ans;
    }
};