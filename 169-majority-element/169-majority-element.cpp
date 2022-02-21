class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Given that majority element always exists in the array 
        // And hence we can now only count the elements and save the element
        // as majority elements occurs more than n/2 times that means other
        // elements occurs less than n/2 
        // so, number of occurrences for majority element>number of occurrences of all other 
        // elements
        int count=0;
        int element=0;
        for(auto x:nums){
            if(count==0){
                // when count becomes 0 then current element will be counted as ans
                element=x;
            }
            if(element==x){
                count++;
                // we're increasing the account if some number is repeating itself
            }else {
                count--;
                // decreasing the count of the repeated element untill it becomes 0 and 
                // when it becomes zero it goes in the first if condition
            }
        }
        // At last majority element will be stored in the element variable
        return element;
    }
};