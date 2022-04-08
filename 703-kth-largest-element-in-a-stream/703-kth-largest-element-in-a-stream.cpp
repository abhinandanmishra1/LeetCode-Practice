class cmp
{
public:
    int operator() (const int& p1, const int& p2)
    {
        return p1> p2;
    }
};
class KthLargest {
public:
    
    priority_queue<int,vector<int>,cmp> pq;
    int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(auto x:nums){
            if(pq.size()<k)
            pq.push(x);
            else{
                if(pq.top()<x){
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }
    
    int add(int x) {  
            if(pq.size()==size){
                if(pq.top()<x){
                    pq.pop();
                    pq.push(x);
            }
            }else{
                pq.push(x);
            }
            return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */