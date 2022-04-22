class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(auto x:deck){
            mp[x]++;
        }
        int store=INT_MAX;
        cout<<endl;
        for(auto x:mp){
            store=min(store,x.second);
        }
        if(store==1) return false;
        for(auto x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<store<<endl;
        for(int i=2;i*i<=store;i++){
            bool ans=false;
            if(store%i==0){    
                for(auto x:mp){
                    if(x.second!=i){
                        if(x.second%i!=0 ){
                            ans=true;
                            break;
                        }  
                    }
                }
                if(!ans) return true;
                int j=store/i;
                ans=false;
                for(auto x:mp){
                    if(x.second!=j){
                        if(x.second%j!=0 ){
                            ans=true;
                            break;
                        }  
                    }
                }
                if(!ans) return true;
            }
        }
        int i=store;
        bool ans=true;
        for(auto x:mp){
                    if(x.second!=i){
                        if(x.second%i!=0 ) return false; 
            }
        }
        return true;
    }
};