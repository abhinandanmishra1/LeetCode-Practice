class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        
        int i=s.length()-1;
        int cnt=0;
        while(i>=0){
            if(s[i]!='-'){
                if(cnt==k){
                    ans.push_back('-');
                    cnt=0;
                }
                if(s[i]>='a' and s[i]<='z'){
                    ans.push_back(s[i]-'a'+'A');
                }else{
                    ans.push_back(s[i]);
                }
                cnt++;
            }
            i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};