class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=min(pre[i-1],nums[i]);
        }
        
        set<int> st;
        st.insert(nums[n-1]);
        for(int j=n-2;j>0;j--){
            auto findThird=st.lower_bound(nums[j]);
            if(findThird!=st.begin()){
                findThird--;
                if(*findThird>pre[j-1]) return true;
            }
            st.insert(nums[j]);
        }
        return false;
    }
};