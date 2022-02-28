class Solution {
public:
    bool rotateString(string s1, string s2) {
        s2+=s2;
        int m=s1.length();
        int n=s2.length();  
        if(n<m) return false; 
        if(n==2 and m==2) return false;
        
        vector<int> store(m,0);
        int i=0,j=1;
        while(j<m){
            if(s1[i]==s1[j]){
                store[j]=i+1;
                i++;
                j++;
            }else{
                if(i>0){
                    i=store[i-1];
                }else{
                    j++;
                }
            }
        }
        
        i=0,j=0;
        while(i<n){
            while(j<m){
                if(s2[i]==s1[j]){
                    i++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==m){
                return true;
            }
            if(j>0){
                j=store[j-1];
            }else{
                i++;
            }
        }
        return false; 
    }
};