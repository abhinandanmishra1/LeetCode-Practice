class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
       int start=-1,end=arr.size();
        int n=arr.size();
        if(n==1) return arr[0];
        while(start+1<end){
            int mid=start+(end-start)/2;
            if(mid>0 and mid<n-1){
                if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]) return arr[mid];
            }
            if(mid==0 and arr[mid]!=arr[mid+1]) return arr[mid];
            if(mid==n-1 and arr[mid]!=arr[mid-1]) return arr[mid];
            
            if(mid&1 and arr[mid-1]==arr[mid]) start=mid;
            else if(!(mid&1) and mid<n-1 and arr[mid]==arr[mid+1]) start=mid;
            else end=mid;
        }
        return arr[end-1];
    }
};