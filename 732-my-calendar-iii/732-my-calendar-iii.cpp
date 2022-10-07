class MyCalendarThree {
public:
    map<int,int> overlaps;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        overlaps[start]++;  // like if there are two events [10,20] [15,20] then ans will be 2 
        // because 10 will come then 15 will come two overlaps
        // if no any event start comes then end of curr event comes and subtracts the count
        overlaps[end]--;
        int sum=0,curr=0;
        for(auto it:overlaps){
            curr+=it.second;
            sum=max(sum,curr);
        }
        return sum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */