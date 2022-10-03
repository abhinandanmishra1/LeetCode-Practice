class Solution {
public:
    int minCost(string &clr, vector<int>& nt) {
        int ans=0;
        
        int i=0,n=clr.length();
        int curr=nt[i++];
        int mx=nt[0];
        while(i<n){
            if(clr[i]==clr[i-1]){
                curr+=nt[i];
                mx=max(mx,nt[i++]);
            }else{
                ans+=(curr-mx);
                curr=nt[i];
                mx=nt[i];
                i++;
            }
        }
        ans+=(curr-mx);
        return ans;
    }
};