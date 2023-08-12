class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m = obstacle.size();
        int n = obstacle[0].size();
        if(obstacle[m-1][n-1]== 1){
            return 0;
        }
        vector<vector<long long>> grid(m, vector<long long>(n,0));
        for(int i = n-1; i>=0; i--){
            if(obstacle[m-1][i]== 1){
                break;
            } 
            grid[m-1][i] = 1;
        }

        for(int i = m-1; i>=0; i--){
            if(obstacle[i][n-1]== 1){
                break;
            }
            grid[i][n-1] = 1;
        }

        // return 0;
        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        grid[m-1][n-1] = 1;
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                if(obstacle[i][j] != 1){
                    grid[i][j] = grid[i+1][j] + grid[i][j+1];
                }
            }
        }
        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return grid[0][0];
    }
};