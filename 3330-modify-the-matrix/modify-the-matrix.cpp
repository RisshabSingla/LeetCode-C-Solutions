class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> highest(m,-1);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                highest[i] = max(highest[i], matrix[j][i]);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = highest[j];
                }
            }
        }
        return matrix;
    }
};