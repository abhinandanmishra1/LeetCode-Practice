// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long mod=1000000007;
    unordered_map<long long int,long long int> dp;
    long long countWays(int n, int k){
        if(n==1) return k;
        if(n==2) return ((long long)k*(long long)k)%mod;
        if(n==0 or k==0) return 0;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        long long ans=((long long)(k-1)*(countWays(n-1,k)%mod+countWays(n-2,k)%mod)%mod)%mod;
        return dp[n]=ans%mod;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends