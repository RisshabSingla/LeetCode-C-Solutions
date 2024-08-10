class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void numberOfIslandsDFS(vector<vector<int>>& matrix, int i, int j, int n,
                            int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] == 1)
            return;
        matrix[i][j] = 1;

        for (auto& dir : directions) {
            int newX = i + dir[0];
            int newY = j + dir[1];
            numberOfIslandsDFS(matrix, newX, newY, n, m);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int regions = 0;

        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    numberOfIslandsDFS(matrix, i, j, n, m);
                    regions += 1;
                }
            }
        }

        return regions;
    }
};