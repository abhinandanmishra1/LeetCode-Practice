class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int,unordered_map<char,int>> mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(auto &x:words[i]){
                mp[i][x]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool f=true;
                for(auto x:mp[i]){
                    if(mp[j].find(x.first)!=mp[j].end()){
                        f=false;
                        break;
                    }
                }
                if(f){
                    int len=words[i].length()*words[j].length();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};