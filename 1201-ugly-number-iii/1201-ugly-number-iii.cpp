#define ll long long
class Solution {
public:
    bool checkPossibility(ll a,ll b,ll c,ll mid,int k){
         // all multiples of a less than mid
        
        long long count=mid/a+mid/b+mid/c;
        
        long long ab=a*b/__gcd(a,b);
        long long bc=b*c/__gcd(b,c);
        long long ac=a*c/__gcd(a,c);
        
        long long abc=a*bc/__gcd((long long)a,bc);
          
        // common multiples of a and b both counted twice
        count-=mid/ab;
        count-=mid/bc;
        count-=mid/ac;
        
        // now multiples of abc was counted thrice by a,b,c
        // removed thrice by ab,bc and ac
        // now add it again 
        
        count+=mid/abc;
        return count>=k;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        
        long long int lo=1,hi=2e9+1;
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(checkPossibility((ll)a,(ll)b,(ll)c,(ll)mid,n)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};