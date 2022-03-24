class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int i=0,j=people.size()-1;
        int count=0;
        while(i<=j){
            if(people[i]+people[j]<=limit)
                i++;
            ans++;    
            j--;
        }
       
        return ans;
    }
};