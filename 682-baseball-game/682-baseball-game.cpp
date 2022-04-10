class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for(auto x:ops){
            if(x=="C"){
                res.pop_back();
            }else if(x=="+"){
                res.push_back(res.rbegin()[0]+res.rbegin()[1]);
            }else if(x=="D"){
                res.push_back(res.back()*2);
            }else{
                res.push_back(stoi(x));
            }
        }
        int ans=accumulate(res.begin(),res.end(),0);
        return ans;
    }
};