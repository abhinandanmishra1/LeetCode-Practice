class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        while(i>=0){
            if(s[i]==' '){
                i--;
            }else{
                break;
            }
        }
        int cnt=0;
        while(i>=0){
            if(s[i]==' '){
                break;
            }else{
                i--;
                cnt++;
            }
        }
        return cnt;
    }
};