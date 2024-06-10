class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        pref = vector<vector<int>>(rows + 1, vector<int>(cols + 1));
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] -
                             pref[i - 1][j - 1] + arr[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] -
               pref[row2 + 1][col1] + pref[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */