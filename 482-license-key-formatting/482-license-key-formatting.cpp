class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string unformat="";
        int i=0;
        while(i<s.length()){
            if(s[i]!='-'){
                if(s[i]>='a' and s[i]<='z'){
                    unformat.push_back(s[i]-'a'+'A');
                }else{
                    unformat.push_back(s[i]);
                }
            }
            i++;
        }
        
        int len=unformat.size();
        if(len==0) return "";
        string ans="";
        int first=len%k;
        first=first==0?k:first;
        ans.push_back(unformat[0]);
        i=1;
        while(i<len){
            if(i==first){
                ans.push_back('-');
                first+=k;
            }
            ans.push_back(unformat[i++]);
        }
        return ans;
    }
};