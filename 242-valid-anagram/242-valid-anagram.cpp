class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char,int> count_s;
        unordered_map<char,int> count_t;
        
        for(auto x:s){
            count_s[x]++;
        }
        
        for(auto x:t){
            count_t[x]++;
        }
        
        for(auto x:s){
            if(count_s[x]!=count_t[x]) return false;
        }
        
        return true;
    }
};