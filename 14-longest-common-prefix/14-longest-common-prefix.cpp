struct trie{
    unordered_map<char,struct trie*> mp;
    bool is_end;
    trie(){
        is_end=false;
    }
};
class Solution {
public:
    struct trie *head;
    void insert(string& s){
        struct trie *curr=head;
        for(auto x:s){
            if(!curr->mp.count(x)){
                curr->mp[x]=new trie;
            }
            curr=curr->mp[x];
        }
        curr->is_end=true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        head=new trie;
        for(auto x:strs){
            insert(x);
        }
        
        string ans="";
        while(1){
            if(head->mp.size()>1 or head->is_end) break;
            for(auto x:head->mp){
                ans.push_back(x.first);
            }
            head=head->mp[ans.back()];
        }
        return ans;
    }
};