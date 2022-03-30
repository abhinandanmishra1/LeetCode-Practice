class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first find the row in which our target can be present
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int n=matrix.size(),m=matrix[0].size();
        
        int l=0,r=n-1;
        int row=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[mid][m-1]==target){
                return true;
            }else if(matrix[mid][m-1]>target){
                row=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};