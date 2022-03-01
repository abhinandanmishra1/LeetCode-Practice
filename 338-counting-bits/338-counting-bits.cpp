class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if(n==0) return ans;
        ans[1]=1;
    
        int prev=1;
        for(int i=2;i<=n;i++){
            if((i&(i-1))==0){
                ans[i]=1;
                prev=i;
            }else{
                ans[i]=(1+ans[i-prev]);
            }
        }
        return ans;
    }
};