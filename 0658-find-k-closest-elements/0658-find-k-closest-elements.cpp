struct Local {
    Local(int x) { this->x = x; }
    bool operator () (int &i, int &j) {
        int diff1=abs(x-i);
        int diff2=abs(x-j);
        if(diff1==diff2) return i>j;
        return diff1>diff2;
    }

    int x;
};
class Solution {
public:    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int,vector<int>,Local> pq((Local(x)));
        for(int y:arr){
            pq.push(y);
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};