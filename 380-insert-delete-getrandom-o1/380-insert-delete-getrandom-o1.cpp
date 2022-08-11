class RandomizedSet {
public:
    set<int> st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.count(val)==1) return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.count(val)==0) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=st.size();
        int i=rand()%n;
        return *next(st.begin(), i);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */