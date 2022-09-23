class Trie {
public:
    unordered_map<char,Trie *> next;
    bool isWord;
    Trie() {
        isWord=false;
    }
    
    void insert(string word) {
        Trie * currNode = this;
        for(auto ch:word){
            if(currNode->next.find(ch)==currNode->next.end()){
                currNode->next[ch] = new Trie();
            }
            currNode = currNode->next[ch];
        }
        currNode->isWord=true;
    }
    
    bool search(string word) {
        Trie * currNode = this;
        for(auto ch:word){
            if(currNode->next.find(ch)==currNode->next.end()){
                return false;
            }
            currNode = currNode->next[ch];
        }
        // check if it's end
        return currNode->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie * currNode = this;
        for(auto ch:prefix){
            if(currNode->next.find(ch)==currNode->next.end()){
                return false;
            }
            currNode = currNode->next[ch];
        }
        // if traversed whole prefix
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */