class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int& m, int& n) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (board[i][j] == '.'){
            return;
        }
        board[i][j] = '.';
        dfs(board, i - 1, j, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
    }
    // void dfs(vector<vector<char>>& board, int x, int y, int m, int n,int
    // type) {
    //     if (type == 1) {
    //         for (int i = x-1; i >= 0; i--) {
    //             if (board[i][y] == 'X') {
    //                 board[i][y] = 'D';
    //             }
    //             if (board[i][y] == '.') {
    //                 break;
    //             }
    //         }
    //         for (int i = x + 1; i < n; i++) {
    //             if (board[i][y] == 'X') {
    //                 board[i][y] = 'D';
    //             }
    //             if (board[i][y] == '.') {
    //                 break;
    //             }
    //         }
    //     }else{
    //         for (int i = y; i >= 0; i--) {
    //             if (board[x][i] == 'X') {
    //                 board[x][i] = 'D';
    //             }
    //             if (board[x][i] == '.') {
    //                 break;
    //             }
    //         }
    //         for (int i = y + 1; i < m; i++) {
    //             if (board[x][i] == 'X') {
    //                 board[x][i] = 'D';
    //             }
    //             if (board[x][i] == '.') {
    //                 break;
    //             }
    //         }
    //     }
    // }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    dfs(board,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};