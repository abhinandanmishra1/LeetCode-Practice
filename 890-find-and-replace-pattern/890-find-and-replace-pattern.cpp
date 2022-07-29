class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> newArray;
        
        for(auto &word:words){
            unordered_map<char,char> patternToWord;
            bool add=true;
            for(int i=0;i<pattern.length();i++){
                if(patternToWord.find(pattern[i])!=patternToWord.end()){
                    if(patternToWord[pattern[i]]!=word[i]){
                        add=false;
                        break;
                    }
                }else{
                    patternToWord[pattern[i]]=word[i];
                }
            }
            
            if(add){
                newArray.push_back(word);
            }
        }
        
        vector<string> ans;
        
        for(auto &word:newArray){
            unordered_map<char,char> wordToPattern;
            bool add=true;
            for(int i=0;i<pattern.length();i++){
                if(wordToPattern.find(word[i])!=wordToPattern.end()){
                    if(wordToPattern[word[i]]!=pattern[i]){
                        add=false;
                        break;
                    }
                }else{
                    wordToPattern[word[i]]=pattern[i];
                }
            }
            
            if(add){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};