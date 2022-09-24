class WordDictionary {
public:
    // unordered_map<char,WordDictionary*> next;
    WordDictionary* next[26]={NULL};
    bool isWord;
    WordDictionary() {
        isWord=false;
    }
    
    void addWord(const string& word) {
        WordDictionary* currNode = this;
        for(auto &ch:word){
            if(currNode->next[ch-'a']==NULL){
                currNode->next[ch-'a'] = new WordDictionary();
            }
            currNode = currNode->next[ch-'a'];
        }
        currNode->isWord=true;
    }

    bool search(const string& word,WordDictionary* currNode=NULL,int ind=0) {
        if(!currNode) currNode = this;
        int i=0;
        for(i=ind;i<word.size();){
            const char &ch=word[i];
            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(!currNode->next[j]){
                        continue;
                    }
                    if(search(word,currNode->next[j],i+1)) return true;
                }
                return false;
                // for(auto &x:currNode->next){
                //     if(search(word,x.second,i+1)){
                //         return true;
                //     }
                // }
                // return false;
            }
            if(currNode->next[ch-'a']==NULL){
                return false;
            }
            i++;
            currNode = currNode->next[ch-'a'];
        }
        return currNode->isWord;
    }
};
