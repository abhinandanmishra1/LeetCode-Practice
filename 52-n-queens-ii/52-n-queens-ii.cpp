class Solution {
public:
    vector<vector<string>> result;
    int totalNQueens(int n) {
        vector<vector<int>> queens;
        
        string s(n,'.');
        vector<string> board(n,s);
        dfs(board,0,queens);
        return result.size();
    }
    
    void dfs(vector<string> board,int row,vector<vector<int>> queens){
            
            if(queens.size()==board.size()){
                result.push_back(board);
             
            } 
            
            for(int col=0;col<board.size();col++){
                if(isPossible(queens,row,col)){
                    board[row][col]='Q';
                    queens.push_back({row,col});
                    dfs(board,row+1,queens);
                    board[row][col]='.';
                    queens.pop_back();
                }
            }
    }
    bool isPossible(vector<vector<int>> &queens,int row,int col){
        for(auto queen:queens){
            int xDiff=abs(row-queen[0]);
            int yDiff=abs(col-queen[1]);
            if(xDiff==0 or yDiff==0 or xDiff==yDiff) return false;
        }
        return true;
    }
};
