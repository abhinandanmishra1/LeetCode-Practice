class Solution {
public:
    bool isSubsequence(string s, string t) {
       int i=0,j=0;
        if(s==t) return true;
        if(s.length()>t.length()){
            return false;
        }
       while(i<t.length()){
           if(s[j]==t[i]){
               j++;
           }
           if(j==s.length()) return true;
           i++;
       }
       return false;
        
    }
};