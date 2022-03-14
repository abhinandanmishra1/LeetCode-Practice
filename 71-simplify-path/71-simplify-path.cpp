class Solution {
public:
    string simplifyPath(string s) {
        string add="";
        vector<string> store;
        for(int i=0;i<s.length();i++){
            if(s[i]!='/'){
                add+=s[i];
            }else{
                 
                if(add=="" or add=="."){
                    add="";
                    continue;
                    // for handling case of /////
                }else if(add==".."){
                    if(store.size()>0) store.pop_back();
                }else{
                    store.push_back(add);
                }
                add="";   
            }
        }
        if(add.size()>0){
            // cout<<add<<endl;
            if(add==".." and store.size()>0){
                store.pop_back();
            }
            if(add!="." and add!="..")
            store.push_back(add);
        }
        string ans="";
        if(store.size()==0) return "/";
        for(auto x:store){
            ans+=("/"+x);
        }
        return ans;
    }
};