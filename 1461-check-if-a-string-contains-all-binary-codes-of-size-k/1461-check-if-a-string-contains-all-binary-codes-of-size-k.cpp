class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> st;
        int f=0;
        int n=s.length();
        if((1<<k)>(n+1-k)) return 0;
        int end=n-k;
        int start=n-1;
        int j=0;
        while(start>=end){
            if(s[start]=='1'){
                f+=(1<<j);
            }
            j++;
            start--;
        }
       
        st.insert(f);
        start=n-k-1;
        while(start>=0){
            f=f>>1;
            if(s[start]=='1'){
                f+=(1<<(k-1));
            }
            st.insert(f);
            start--;
        }
        return st.size()==(1<<k);
    }
};