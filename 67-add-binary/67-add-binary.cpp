class Solution {
public:
    string addBinary(string a, string b) {
        int aSize=a.length();
        int bSize=b.length();
        string ans="";
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        
        int i=0;
        int carry=0;
        while(i<aSize and i<bSize){
            int sum=(a[i]-'0')+(b[i]-'0')+carry;
            carry=sum/2;
            sum=sum%2;
            ans+=char(sum+'0');
            i++;
        }
        while(i<aSize){
            int sum=(a[i]-'0')+carry;
            carry=sum/2;
            sum=sum%2;
            ans+=char(sum+'0');
            i++;
        }
        
        while(i<bSize){
            int sum=(b[i]-'0')+carry;
            carry=sum/2;
            sum=sum%2;
            ans+=char(sum+'0');
            i++;
        }
        
        if(carry){
            ans+=char(carry+'0');
        }
        
        reverse(begin(ans),end(ans));
        return ans;
        
    }
};