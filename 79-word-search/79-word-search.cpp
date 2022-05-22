class Solution {
public:
   bool dfs(vector<vector<char>> &board,int i,int j,int x,string s){
    if(x==s.length()) return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() ) return false;
    if(board[i][j] != s[x])  return false;
       
    char temp=board[i][j];
    board[i][j]='$';
    if(dfs(board,i-1,j,x+1,s)||dfs(board,i,j-1,x+1,s)||dfs(board,i+1,j,x+1,s)||dfs(board,i,j+1,x+1,s)) return true;
    board[i][j]=temp;
    return false;
  }
    bool exist(vector<vector<char>>& board, string word) {
      
        for(int i=0;i<board.size();i++){
          for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){
               bool ans=dfs(board,i,j,0,word);
              if(ans) return 1;
             
            }
          }
        }
      return false;
    }

};
