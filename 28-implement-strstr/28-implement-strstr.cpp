class Solution {
public:
    int strStr(string s1, string s2) {
    
        
       if((s1.size()==1 and s2.length()<=1) or (s1.length()==0 and s2.length()==0)) return 0;
       string tot=s2+"$"+s1;
       int n=tot.length();
        vector<int> store(n,0);
        int l=0,r=0;
       
        for(int i=0;i<n;i++){
            if(i>r){
                l=i,r=i;
                while(r<n and tot[r]==tot[r-l]) r++;
                store[i]=r-l;
                r--;
            }else{
                int ind=i-l;
                if(i+store[ind]<=r) store[i]=store[ind];
                else{
                    l=i;
                    while(r<n and tot[r]==tot[r-l]) r++;
                    store[i]=r-l;
                    r--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(store[i]==s2.length()){
                return i-s2.length()-1;
            }
        }
        return -1;
    }
};