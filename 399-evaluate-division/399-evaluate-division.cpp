class Solution {
public:
    unordered_map<string,double> mp;
    unordered_map<string,vector<string>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]+"$"+equations[i][1]]=values[i];
            mp[equations[i][1]+"$"+equations[i][0]]=1.0/values[i];
            graph[equations[i][0]].push_back(equations[i][1]);
            graph[equations[i][1]].push_back(equations[i][0]);
        }
        vector<double> ans;
        for(auto arr:queries){
            queue<pair<string,double>> q;
            q.push({arr[0],1.0});
            unordered_map<string,bool> visited;
            visited[arr[0]]=true;
            bool done=false;
            if(arr[0]==arr[1]){
                if(graph.find(arr[0])!=graph.end())
                ans.push_back(1.0);
                else
                    ans.push_back(-1.0);
                continue;
            }
            while(!q.empty()){
                auto curr=q.front();
                q.pop();
                string s=curr.first;
                double val=curr.second;
                
                for(auto x:graph[s]){
                    if(!visited[x]){
                        if(x==arr[1]){
                            done=true;
                            ans.push_back(val*mp[s+"$"+x]);
                            break;
                        }
                        q.push({x,val*mp[s+"$"+x]});
                        visited[x]=true;
                        cout<<(s+"/"+x)<<endl;
                    }
                }
                if(done) break;
            }
            if(!done) ans.push_back(-1.0);
        }
        return ans;
    }
};