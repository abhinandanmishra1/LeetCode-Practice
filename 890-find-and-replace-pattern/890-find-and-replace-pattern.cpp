class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &word:words){
            unordered_map<char,char> mp;
            unordered_map<char,char> visited;
            int i=0;
            for(i=0;i<pattern.length();i++){
                if(mp.find(pattern[i])!=mp.end()){
                    if(mp[pattern[i]]!=word[i]) break;
                }else{
                    if(visited.find(word[i])!=visited.end()){
                        if(visited[word[i]]!=pattern[i]) break;
                    }
                    mp[pattern[i]]=word[i];
                    visited[word[i]]=pattern[i];
                }
            }
            
            if(i==pattern.length()){
                ans.push_back(word);
            }
        }
        return ans;
    }
};