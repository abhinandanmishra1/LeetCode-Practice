#define ll long long 
class Solution {
public:
    
    ll countDigitsUpToN(ll n){
        ll digit=0;
        ll k=n;
        while(k>0){
            digit++;
            k/=10;
        }
        if(digit==1) return n;
        
        ll curr=digit;
        ll count=0;
        
        ll a=1,b=9;
        while(a<digit){
            count+=a*b;
            a++;
            b*=10;
        }
       
        count+=curr*(n-(long long)pow(10,curr-1)+1);
        return count;
    }
    int findNthDigit(int n) {
        
        long long start=0,end=1e10;
        
        while(start+1<end){
            ll mid=start+(end-start)/2;
            ll ans=countDigitsUpToN(mid);
            if(ans<n){
                start=mid;
            }
            else{
                end=mid;
            }
        }
        
        ll prevcount=countDigitsUpToN(start);
        ll digitIndex=n-prevcount;
        string number=to_string(start+1);
        return number[digitIndex-1]-'0';
    }
};