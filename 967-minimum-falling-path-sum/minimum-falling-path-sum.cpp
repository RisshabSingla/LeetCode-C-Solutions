class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int>(m,0));
        vector<int> prev(m,0);
        vector<int> next(m,0);
        for(int i = 0; i<m; i++){
            prev[i] = matrix[0][i];
        }
        for(int i = 1; i<n; i++){
            next[0] = min(prev[0],prev[1]) + matrix[i][0];
            next[m-1] = min(prev[m-2],prev[m-1]) + matrix[i][m-1];
            for(int j = 1; j<m-1; j++){
                next[j] = min({prev[j-1], prev[j], prev[j+1]}) + matrix[i][j];
            }
            prev = next;
        }

        int ans = INT_MAX;
        for(int i = 0; i<m; i++){
            ans = min(ans, prev[i]);
        }
        return ans;
    }
};