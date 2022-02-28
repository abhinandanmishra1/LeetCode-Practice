class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n=s.length();
        if(n==1) return false;
       for(int i=1;i*i<=n;i++){
           if(n%i==0){
               string check=s.substr(0,i);
               int cnt=n/i;
               string add="";
               while(cnt--){
                   add.append(check);
               }
               if(add==s) return true;
               if(i==1) continue;
               check=s.substr(0,n/i);
               cnt=i;
               add="";
               while(cnt--){
                   add.append(check);
               }
               if(add==s) return true;
           }
       }
        return false;
        
    }
};