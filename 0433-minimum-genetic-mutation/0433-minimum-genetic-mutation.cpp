class Solution {
public:
    bool visited[10]= {false};
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end) return 0;
        
        int ans=INT_MAX;
        for(int i=0;i<bank.size();i++){
            int diff=0;
            if(!visited[i]){
                for(int j=0;j<8;j++){
                    if(bank[i][j]!=start[j]){
                        diff++;
                    }
                    if(diff>1) break;
                }

                if(diff==1){
                    visited[i]=true;
                    int nextAns = minMutation(bank[i],end,bank);
                    visited[i]=false;
                    if(nextAns==-1){
                        continue;
                    }
                    ans=min(ans,1+nextAns);
                }
            }
        }
        
        return ans==INT_MAX?-1:ans; 
    }
};