class Solution {
public:
    int strStr(string s1, string s2) {
        // I have to return the first occurrence of s2 in s1
       int n=s1.length();
       int m =s2.length();
       // for this I can use KMP algorithm 
       // Let's understand how it works
        if(n<m) return -1;
        if(s1==s2) return 0;
    /*
       s1=hello
       s2=ll 
       
       we have to make a store array which will store
       the s2 indices where prefix of the string is equal to suffix
       for each substring of (0 to i) (where i=0 to m)
    */
      vector<int> store(m,0);
      int i=0,j=1;
        while(j<m){
            if(s2[i]==s2[j]){
                i++;
                store[j]=i;  // length = i+1
                j++;
            }else{
                if(i>0){
                    i=store[i-1];
                }else{
                    j++;
                }
            }
            
        }
        // now our array is maintained 
        // Main Kmp traversal 
        
        i=0,j=0;
        while(i<n){
            while(j<m){
                if(s1[i]==s2[j]){
                    i++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==m){
                // patter is found
                return i-m; // return starting index that is i-m
            }
            
            if(j>0){
                j=store[j-1];
            }else{
                i++;
            }
        }
        return -1; /// if pattern not found
        
    }
};