class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> dir1={0,0,1,-1,1,1,-1,-1};
        vector<int> dir2={1,-1,0,0,-1,1,-1,1};
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=board[i][j];
                if(board[i][j]){
                    int count=0;
                    for(int k=0;k<8;k++){
                        int ii=i+dir1[k];
                        int jj=j+dir2[k];
                        if(ii<0 or jj<0 or ii>=n or jj>=m) continue;
                        count+=board[ii][jj];
                    }
                    if(count<2 or count>3){
                        res[i][j]=0;
                    }
                }else{
                    int count=0;
                    for(int k=0;k<8;k++){
                        int ii=i+dir1[k];
                        int jj=j+dir2[k];
                        if(ii<0 or jj<0 or ii>=n or jj>=m) continue;
                        count+=board[ii][jj];
                    }
                    if(count==3){
                        res[i][j]=1;
                    }
                }
            }
           
        }
         board=res;
    }
};