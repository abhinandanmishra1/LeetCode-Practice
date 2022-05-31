class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int f=0;
        int n=s.length();
        // checking if number of substrings of length k is less than required number
        // then answer will be false or 0 
        int requiredCounts=1<<k;
        if((requiredCounts)>(n+1-k)) return 0;
        int end=n-k;
        int start=n-1;
        int j=1;
        // K times
        while(start>=end){
            if(s[start]=='1'){
                f+=j;
            }
            j*=2;
            start--;
        }
        // Now in f the value of last k bits in integer format will be stored
        st.insert(f);
        start=n-k-1;
        // each time I'm removing last bit 
        // adding kth bit into it 
        int kthBit=(1<<(k-1));
        while(start>=0){
            f=f>>1; // removing the last bit 
            if(s[start]=='1'){ // if kth bit is set then add it to the answer
                f+=kthBit;
            }
            st.insert(f);
            start--;
        }
        return st.size()==requiredCounts;
    }
};