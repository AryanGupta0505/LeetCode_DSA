class Solution {
public:
    bool solve(vector<vector<char>> &board,int row,int col,int index,string word,int m,int n){
        if(index>=word.size()){
            return true;
        }
        if(row<0|| row>=m ||col<0||col>=n||board[row][col]!=word[index]){
            return false;
        }
        char temp=board[row][col];
        board[row][col]='.';
        if(solve(board,row+1,col,index+1,word,m,n)||
        solve(board,row-1,col,index+1,word,m,n)||
        solve(board,row,col+1,index+1,word,m,n)||
        solve(board,row,col-1,index+1,word,m,n)){
            return true;
        }
        board[row][col]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,i,j,0,word,m,n))
                    return true;
            }
        }
        return false;
    }
};