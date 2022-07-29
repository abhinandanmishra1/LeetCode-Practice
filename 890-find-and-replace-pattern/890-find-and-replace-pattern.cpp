class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto &word:words){
            unordered_map<char,char> patternToWord;
            unordered_map<char,char> wordToPattern;
            bool addToAnswer=true;
            for(int i=0;i<pattern.length();i++){
                if(patternToWord.find(pattern[i])!=patternToWord.end()){
                    if(patternToWord[pattern[i]]!=word[i]){
                        addToAnswer=false;
                        break;
                    }
                }else{
                    if(wordToPattern.find(word[i])!=wordToPattern.end()){
                        if(wordToPattern[word[i]]!=pattern[i]){
                            addToAnswer=false;
                            break;
                        }
                    }
                    patternToWord[pattern[i]]=word[i];
                    wordToPattern[word[i]]=pattern[i];
                }
            }
            
            if(addToAnswer){
                ans.push_back(word);
            }
        }
        return ans;
    }
};