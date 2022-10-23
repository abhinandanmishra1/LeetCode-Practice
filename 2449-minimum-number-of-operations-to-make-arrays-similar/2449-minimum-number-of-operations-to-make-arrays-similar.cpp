class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        // even number will play with even 
        // odd will play with odd
        
        vector<vector<int>> even(2),odd(2);
        for(auto x:nums){
            if(!(x&1)){
                even[0].push_back(x);
            }else{
                odd[0].push_back(x);
            }
        }
          for(auto x:target){
            if(!(x&1)){
                even[1].push_back(x);
            }else{
                odd[1].push_back(x);
            }
        }
        
        for(int i=0;i<2;i++){
            sort(begin(even[i]),end(even[i]));
            sort(begin(odd[i]),end(odd[i]));
        }
        
        long long ans=0;
        for(int i=0;i<even[0].size();i++){
            ans+=abs(even[0][i]-even[1][i])/2;
        }
        for(int i=0;i<odd[0].size();i++){
            ans+=abs(odd[0][i]-odd[1][i])/2;  // because 2 increase and decrease
        }
        return ans/2;  // because in one operation one add and one subtract
    }
};