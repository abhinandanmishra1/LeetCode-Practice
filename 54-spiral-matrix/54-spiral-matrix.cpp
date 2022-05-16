class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0,bottom=m-1,left=0,right=n-1;
        int dir=0;
        // 0-> L to R
        // 1-> T to B
        // 2-> R to L
        // 3-> B to T
        vector<int> ans;
        while(top<=bottom and left<=right){
            if(dir==0){
                // left to right
                for(int i=left;i<=right;i++) ans.push_back(matrix[top][i]);
                top++; // increase row
            }else if(dir==1){
                // top to bottom
                for(int i=top;i<=bottom;i++){
                   ans.push_back(matrix[i][right]); 
                }
                
                right--; //decrease col
            }else if(dir==2){
                // right to left
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                    
                }
                bottom--;
            }else{
                // bottom to top
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]); 
                }
                left++;
            }
            
            dir=(dir+1)%4;
        }
        return ans;
    }
};