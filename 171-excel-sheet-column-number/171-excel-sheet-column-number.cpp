class Solution {
public:
    int titleToNumber(string s) {
        int n=s.size();
        if(n==1){
            return s[0]-'A'+1;
        }
        // int ans=pow(26,n-1);
        int ans=0;
        int add=1;
        for(int i=0;i<n;i++){
            add=(s[i]-'A'+1);
            ans=ans*26+add;
        }
        
        return ans;
    }
};