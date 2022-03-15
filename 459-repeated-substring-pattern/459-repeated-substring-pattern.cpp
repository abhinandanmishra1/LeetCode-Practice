class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n=s.length();
        vector<int> store(n,0);
        int i=0,j=1;
        while(j<n){
            if(s[i]==s[j]){
                store[j]=i+1;
                i++,j++;
            }else{
                if(i!=0){
                    i=store[i-1];
                }else{
                    j++;
                }
            }
        }
        int patternLength=n-store.back();
        if(store.back()>0 and n%patternLength==0) return true;
        return false;    
        
    }
};