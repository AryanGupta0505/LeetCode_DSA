class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int x = row;
        int y = col;
        while (y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            y--;
        }
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string>& board, int n) {
        if (col == n) {
            // ans++;
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                board[row][col] = '.'; 
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // int ans=0;
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans.size();
    }
};