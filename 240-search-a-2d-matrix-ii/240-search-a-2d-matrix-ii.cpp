class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        long int rows=matrix.size();
        long int cols=matrix[0].size();
        for(int row=0;row<rows;row++){
            int start=-1,end=cols;
            while(start+1<end){
                int mid=start+(end-start)/2;
                if(matrix[row][mid]<=target){
                    start=mid;
                }else{
                    end=mid;
                }
            } 
            if(start>=0 and start<cols and matrix[row][start]==target) return true;
        }

        return false;
        
    }
};