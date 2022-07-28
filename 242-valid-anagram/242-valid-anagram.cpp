class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        
        unordered_map<char,int> count;
        
        for(auto x:s){
            count[x]++;
        }
        
        for(auto x:t){
            count[x]--;
        }
        
        for(auto x:s){
            if(count[x]!=0) return false;
        }
        
        return true;
    }
};