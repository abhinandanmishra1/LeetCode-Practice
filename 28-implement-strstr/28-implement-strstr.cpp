class Solution {
public:
    int strStr(string s1, string s2) {
        // I have to return the first occurrence of s2 in s1
        if(s1==s2) return 0;
       int n=s1.length();
       int m =s2.length();
       if(n<m) return -1;
        vector<int> store(m,0);
        int i=0,j=1;
        while(j<m){
            if(s2[i]==s2[j]){
                store[j++]=++i;
            }else{
                if(!i){
                    j++;
                }else{
                    i=store[i-1];
                }
            }
        }
        i=0,j=0;
        while(i<n){
            while(j<m and s1[i]==s2[j]){
                i++;
                j++;
            }
            if(j==m) return i-m;
            if(j>0){
                j=store[j-1];
            }else{
                i++;
            }
        }
        return -1;
    }
};