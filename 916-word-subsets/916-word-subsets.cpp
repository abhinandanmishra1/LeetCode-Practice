class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> store;
        for(auto &word:words2){
            
            unordered_map<char,int> counter;
            for(auto &x:word){
                counter[x]++;
                store[x]=max(store[x],counter[x]);
            }
            
        }
        
        vector<string> ans;
        
        for(auto &word:words1){
            unordered_map<char,int> counter;
            for(auto &x:word){
                counter[x]++;
            }
            bool add=true;
            for(auto &letter_count:store){
                if(counter[letter_count.first]<letter_count.second){
                    add=false;
                    break;
                }
            }
            if(add){
                ans.push_back(word);
            }
        }
        return ans;
    }
};