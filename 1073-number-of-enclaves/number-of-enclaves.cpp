class Solution {
public:
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    void bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int i,
             int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = p.first + dirX[k];
                int y = p.second + dirY[k];
                if(x>=0 && x<n && y>=0 && y<m){
                    if(board[x][y] == 1 && !visited[x][y]){
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            // left column
            if (board[i][0] == 1 && !visited[i][0]) {
                visited[i][0] = true;
                bfs(board, visited, i, 0, n, m);
            }
            // right column
            if (board[i][m - 1] == 1 && !visited[i][m - 1]) {
                visited[i][m - 1] = true;
                bfs(board, visited, i, m - 1, n, m);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 1 && !visited[0][i]) {
                // top row
                visited[0][i] = true;
                bfs(board, visited, 0, i, n, m);
            }
            if (board[n - 1][i] == 1 && !visited[n - 1][i]) {
                // bottom row
                visited[n - 1][i] = true;
                bfs(board, visited, n - 1, i, n, m);
            }
        }

        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};