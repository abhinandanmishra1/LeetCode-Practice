class Solution {
public:
    vector<bool> visited;
    bool dfs(int i,vector<int>& left,vector<int>& right){
        if(i==-1 or visited[i]) return false;
        visited[i]=true;
        if(left[i]!=-1 and !dfs(left[i],left,right)) return false;
        if(right[i]!=-1 and !dfs(right[i],left,right)) return false;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       vector<int> parent(n,-1);
        visited.resize(n,false);
       for(int i=0;i<n;i++){
           if(leftChild[i]!=-1){
               if(parent[leftChild[i]]!=-1) return false;
               parent[leftChild[i]] =i; 
           }
           if(rightChild[i]!=-1){
               if(parent[rightChild[i]]!=-1) return false;
               parent[rightChild[i]] =i;
           }    
       }
       int nodesWithNoParents = 0;
       int node = -1;
       for(int i=0;i<n;i++){
           if(parent[i]==-1){
               nodesWithNoParents++;
                if(nodesWithNoParents>1) return false;
               node = i;
           }
           
       }
        if(nodesWithNoParents!=1 or !dfs(node,leftChild,rightChild)) return false;
        for(int i=0;i<n;i++) if(!visited[i]) return false;
        return true;
    }
};