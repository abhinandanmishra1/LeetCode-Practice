class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        for(auto x:s){
            if(x!='#'){
                s1.push_back(x);
            }else{
                if(s1.size()>0)
                s1.pop_back();
            }
        }
        string s2="";
        for(auto x:t){
            if(x!='#'){
                s2.push_back(x);
            }else{
                if(s2.size()>0)
                s2.pop_back();
            }
        }
        return s1==s2;
    }
};