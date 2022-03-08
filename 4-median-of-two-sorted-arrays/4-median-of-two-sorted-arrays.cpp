class Solution {
public:
    void merge(vector<int> &arr,vector<int> &arr1,vector<int> &arr2){
        int n=arr1.size();
        int m=arr2.size();
        int k=0;
        int i=0,j=0;
        while(i<n and j<m){
            if(arr1[i]<arr2[j]){
                arr[k++]=arr1[i++];
            }else{
                arr[k++]=arr2[j++];
            }
        }
        while(j<m){
            arr[k++]=arr2[j++];
        }
        while(i<n){
            arr[k++]=arr1[i++];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        n+=m;
        vector<int> arr(n);
        merge(arr,nums1,nums2);
        if(n&1){
            return arr[n/2]*1.0;
        }
        return (arr[n/2]*1.0+arr[n/2-1]*1.0)/2.0;
    }
};