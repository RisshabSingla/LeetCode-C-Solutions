class Solution {
public:
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    bool bfs(vector<vector<char>>& board, vector<vector<bool>>& visited,char ch,  int i, int j, int n, int m){
        queue<vector<int>> q;
        q.push({i,j, i,j});
        while(!q.empty()){
            vector<int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = p[0] + dirX[k];
                int y = p[1] + dirY[k];
                if(x>=0 && x<n && y>=0 && y<m && (x != p[2] || y != p[3])){
                    if(visited[x][y] && board[x][y] == ch){
                        return true;
                    }
                    if(board[x][y] == ch){
                        visited[x][y] = true;
                        q.push({x,y, p[0], p[1]});
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && bfs(grid, visited, grid[i][j], i, j, n, m)){
                    return true;
                }
            }
        }
        return false;
    }
};