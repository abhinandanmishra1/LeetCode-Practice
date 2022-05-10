class RandomizedCollection {
public:
    unordered_map<int,vector<int>> mp;
    // map is used to store all the indexes of each value the array
    vector<int> arr;
    int index=0;
    RandomizedCollection() {
        mp.clear();
        arr.clear();
        index=0;
    }
    
    bool insert(int val) {
        mp[val].push_back(index++);
        arr.push_back(val);
        
        return mp[val].size()==1;
        // size will be 1 if item was not present previously and it will true then
        // otherwise return false
    }
    
    bool remove(int val) {
        if(mp[val].size()>0){
            // The item is present in the multiset
            int itemInd=mp[val].back();
            mp[val].pop_back();  // remove index from map
            
        // to remove the element from the array 
        // swap the given element with the last element
        // store the element that was present at last place in a lastElement
        // now go to the mp[lastElement] and remove last index because it 
        // got changed and then push itemInd into it -> New index of lastElement
            
            int lastElement=arr.back();
            swap(arr[index-1],arr[itemInd]);
            // now val is at indexth position
            // lastElement is at indth position
            if(index-1!=itemInd)
            {
                mp[lastElement].pop_back();  // remove index from it
                 mp[lastElement].push_back(itemInd); // new Index of the lastElement
            }
            
            // Now remove the val by popping back and decrease index by 1
            arr.pop_back();
            index--;
            
            // sort the indexes of lastElement
            sort(mp[lastElement].begin(),mp[lastElement].end());
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        int n=rand()%index;
        return arr[n];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */