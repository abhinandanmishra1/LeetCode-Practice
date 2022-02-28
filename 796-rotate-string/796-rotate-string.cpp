class Solution {
public:
    bool rotateString(string s1, string s2) {
        /*
            We have to check whether the string s1 can be converted 
            to string s2 after some shifts.
            Shifts means shifting leftmost char from s1 to rightmost position
            
            s1- abcde
            s2- cdeab
            
            Shift one char of s1
            s1 - bcdea
            
            Shift one char from s1
            s1- cdeab  -- this is equal to s2
            
            Intuition - 
            We can check for each rotation also.
            
            But if we double s2 by s2=s2+s2 
            that is for above example - s2= bcdeabcdea
            then if s1 is a substring of the new s2 then return true else return false;
            
            We can use KMP algorithm for that. 
        */
        s2+=s2;
        int m=s1.length();
        int n=s2.length();  // s2 is greater
        if(n<=m) return false; 
        
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
        
        // Now traverse both the strings using store array 
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
                // substring is found 
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