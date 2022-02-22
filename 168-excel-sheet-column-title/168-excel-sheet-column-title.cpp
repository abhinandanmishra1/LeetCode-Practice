class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber){
            int rem=columnNumber%26;
            if(rem>=1){
                ans+=rem-1+'A';
            }else{
                ans+=('Z');
                columnNumber--;
            }
            
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};