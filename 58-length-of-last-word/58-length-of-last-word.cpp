class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1; // last position of the given s
        while(i>=0){
            if(s[i]==' '){
                i--;
            }else{
                break;
            }
        }
        // now this i is the last letter of the last word
        // for moon in ex 2 i pos of n
        
        // count the len of this word
        int count=0;
        while(i>=0){
            if(s[i]==' ') break;
            count++;
            i--;
        }
        return count;
        
    }
};

// "          "