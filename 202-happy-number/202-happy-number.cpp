class Solution {
public:
    unordered_map<int,int> visited;
    bool isHappy(int n) {
        if(visited.find(n)!=visited.end()) return false;
        if(n==1) return true;
        int newNum=0;
        visited[n]++;
        while(n){
            newNum+=(n%10)*(n%10);
            n/=10;
        }
        return isHappy(newNum);
    }
};