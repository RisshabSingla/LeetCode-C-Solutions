class Solution {
public:
    bool isPossible(vector<vector<int>>& grid, int x, int y, int n, int m) {
        vector<int> arr(10, 0);
        vector<int> rowSum(3, 0);
        vector<int> colSum(3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[x + i][y + j] <= 0 || grid[x + i][y + j] > 9) {
                    // cout<<"False due to out of range\n";
                    return false;
                }
                rowSum[i] += grid[x + i][y + j];
                colSum[j] += grid[x + i][y + j];
                arr[grid[x + i][y + j]]++;
            }
        }

        for (int i = 1; i < 10; i++) {
            if (arr[i] != 1) {
                // cout<<"False due to count: "<<i<<"\n";
                return false;
            }
        }
        int sum = rowSum[0];
        for (int i = 0; i < 3; i++) {
            if (rowSum[i] != sum) {
                // cout<<"False due to rowCount: "<<i<<"\n";
                return false;
            }
            if (colSum[i] != sum) {
                // cout<<"False due to colCount: "<<i<<"\n";
                return false;
            }
        }
        int diag1Sum = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int diag2Sum = grid[x][y+2] + grid[x + 1][y + 1] + grid[x + 2][y];
        if(diag1Sum != sum || diag2Sum != sum){
            // cout<<"False due to Diagonal: "<<"\n";
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isPossible(grid, i, j, n, m)) {
                    count++;
                }
            }
        }
        return count;
    }
};