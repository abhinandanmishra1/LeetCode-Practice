class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto &x:words){
            mp[x]++;
        }
        vector<int> ans;
        int len=words[0].length();
        int n=words.size();
        int total=n*len;
        if(s.length()<total) return {};
        for(int i=0;i<=s.length()-total;i++){
            unordered_map<string,int> store;
            int count=0;
            // cout<<"\ni "<<i<<endl;
            while(count<words.size()){
                int start=count*len+i;
                string sub=s.substr(start,len);
                // cout<<sub<<endl;
                if(mp.find(sub)==mp.end()) break;
                if(mp[sub]<store[sub]+1) break;
                store[sub]++;
                count++;
            }
            if(count==words.size()) ans.push_back(i);
        }
        return ans;
    }
};