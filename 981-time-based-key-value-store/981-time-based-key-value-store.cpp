class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        store.clear();
    }
    
    void set(const string &key, const string &value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(const string &key, int timestamp) {
        int largestIndex=store[key].size();
        if(largestIndex==0) return "";
        //cout<<key<<" "<<timestamp;
        int lo=0,hi=largestIndex-1;
        auto &arr = store[key];
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid].first>timestamp){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        //cout<<" "<<lo<<" "<<arr[lo].second<<endl;
        return arr[lo].first>timestamp?(lo>0?arr[lo-1].second:""):arr[lo].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */