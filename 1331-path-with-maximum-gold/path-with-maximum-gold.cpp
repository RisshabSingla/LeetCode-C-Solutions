class Solution {
public:
    int dirX[4] = {0,0,1,-1};
    int dirY[4] = {1,-1,0,0};
    int findCollect(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<bool>>& visited){
        int maxi = 0;
        for(int k = 0; k<4; k++){
            int x = i+dirX[k];
            int y = j+dirY[k];
            if(x>=0&& x< n && y>=0 && y<m && !visited[x][y] && grid[x][y]){
                visited[x][y] = true;
                int collect = findCollect(grid, x,y, n,m, visited) + grid[x][y];
                maxi = max(maxi, collect);
                visited[x][y] = false;
            }
        }
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                visited[i][j] = true;
                int collect = findCollect(grid, i,j, n,m, visited) + grid[i][j];
                maxi = max(collect, maxi);
            }
        }
        return maxi;
    }
};