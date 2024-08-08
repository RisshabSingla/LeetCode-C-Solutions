class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int step = 0;
        int index = 0;
        int x = rStart;
        int y = cStart;
        int total = rows * cols;
        ans.push_back({x, y});
        while (ans.size() < total) {
            if (index % 2 == 0) {
                step++;
            }

            for (int i = 0; i < step; i++) {
                x += directions[index][0];
                y += directions[index][1];

                if (x >= 0 && x < rows && y >= 0 && y < cols)
                    ans.push_back({x, y});
            }

            index = (index + 1) % 4;
        }
        return ans;
    }
};