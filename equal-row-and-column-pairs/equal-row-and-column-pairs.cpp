class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        // Approach 1: Brute Force
        // int n = grid.size();
        // vector<int> row_sum(n,0);
        // vector<int> column_sum(n,0);
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         row_sum[i]+=grid[i][j];
        //         column_sum[i] += grid[j][i];
        //     }
        // }

        // int count = 0;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         if(row_sum[i] == column_sum[j]){
        //             bool equal = true;
        //             for(int k = 0; k<n; k++){
        //                 if(grid[i][k] != grid[k][j]){
        //                     equal = false;
        //                     break;
        //                 }
        //             }
        //             if(equal){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;


        // Approach 2: Using maps

        map<vector<int>, int> rows;
        int n = grid.size();
        for(int i = 0; i<n; i++){
            rows[grid[i]]++;
        }

        int count = 0;
        for(int i = 0; i<n; i++){
            vector<int> column(n);
            for(int j = 0; j<n; j++){
                column[j] = grid[j][i];
            }
            count+=rows[column];
        }
        return count;

    }
};