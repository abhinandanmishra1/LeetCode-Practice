class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;
        vector<int> count(256,-1);
        for(int i=0;i<s.length();i++){
            int x=s[i];
            if(count[x]==-1){
                count[x]=i;
                ans=max(ans,i-start+1);
            }else{
                if(count[x]>=start){
                   
                    start=count[x]+1;
                    count[x]=i;
                    
                    ans=max(ans,i-start+1);
                }else{
                    count[x]=i;
                    ans=max(ans,i-start+1);
                }
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};