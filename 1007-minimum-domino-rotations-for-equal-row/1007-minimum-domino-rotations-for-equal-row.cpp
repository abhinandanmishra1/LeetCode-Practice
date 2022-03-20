
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> mp;
        int cnt=0;
        unordered_map<int,int> mp2,mp3;
        for(int i=0;i<tops.size();i++){
            if(tops[i]!=bottoms[i]){
                mp[tops[i]]++;
                mp[bottoms[i]]++;
                
            }else{
                mp[tops[i]]++;
            }
            mp2[tops[i]]++;
            mp3[bottoms[i]]++;
            cnt=max({cnt,mp[tops[i]],mp[bottoms[i]]});
        }
        
        if(cnt<tops.size()) return -1;
        
        vector<int> possible;
        for(auto x:mp){
            if(x.second==tops.size()){
                possible.push_back(x.first);
            }
        }
        
        int ans=INT_MAX;
        int len=tops.size();
        for(int x:possible){
            ans=min({ans,(len-mp3[x]),(len-mp2[x])});
            // cout<<ans<<" "<<x<<endl;
        }
        
        return ans;
        
    }
};