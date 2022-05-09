class Solution {
public:
    vector<string> store={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void findans(string digits,int i,vector<string>& ans,string s){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        int x=digits[i]-'0';
        for(char c:store[x]){
            findans(digits,i+1,ans,s+c);
        }
    }
    
    vector<string>  letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        findans(digits,0,ans,"");
        return ans;
    }
};