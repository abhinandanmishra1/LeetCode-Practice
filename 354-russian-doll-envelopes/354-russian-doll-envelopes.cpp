/*
// Dp solution 
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Dp solution is giving tle on one testcase 
        // because length is 10^5 and solution is in O(n^2)
        
        int n=envelopes.size();
        vector<int> dp(n,1);
        sort(envelopes.begin(),envelopes.end());
        int w=0,h=0;
        int checkAns=0;
        for(auto &arr:envelopes){
            if(arr[0]>w and arr[1]>h){
                checkAns++;
                w=arr[0];
                h=arr[1];
            }
        }
        if(checkAns==n) return n;
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};

*/

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](vector<int>&A,vector<int>&B){
            if(A[0]!=B[0]) return A[0]<B[0];
            return A[1]>B[1];
        });
        
        vector<int> lis;
        // LIS on heights
        for(auto &x:env){
            auto it=lower_bound(lis.begin(),lis.end(),x[1]);
            if(it==lis.end()) lis.push_back(x[1]);
            else *it=x[1];
        }
        return lis.size();
            
        
    }
};