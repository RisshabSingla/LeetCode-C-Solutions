class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i<min(n, m); i++){
            ans[i][i] = min(rowSum[i], colSum[i]);
            rowSum[i]-= ans[i][i];
            colSum[i]-= ans[i][i];
        }

        for(int i = 0; i<n; i++){
            if(rowSum[i] == 0){
                continue;
            }
            for(int j = 0; j<m; j++){
                if(colSum[j] == 0){
                    continue;
                }
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];
            }
        }
        return ans;
    }
};