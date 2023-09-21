class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // Approach 1: Using vectors

        vector<pair<int,int>> indexes;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(matrix[i][j] == 0){
                    indexes.push_back({i,j});
                }
            }
        }
        
        if(indexes.size() == 0){
            return;
        }
        for(int i = 0; i<indexes.size(); i++){
            int x = indexes[i].first;
            int y = indexes[i].second;
            for(int c = 0; c<cols; c++){
                matrix[x][c] = 0;
            }
            for(int r = 0; r<rows; r++){
                matrix[r][y] = 0;
            }
        }


        // Approach 2: Using maps
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        // unordered_set<int> row;
        // unordered_set<int> column;
        // for(int i = 0; i<rows; i++){
        //     for(int j = 0; j<cols; j++){
        //         if(matrix[i][j] == 0){
        //             row.insert(i);
        //             column.insert(j);
        //         }
        //     }
        // }

        // for(auto i: row){
        //     for(int j = 0; j<cols; j++){
        //         matrix[i][j] = 0;
        //     }
        // }

        // for(auto j: column){
        //     for(int i = 0; i<rows; i++){
        //         matrix[i][j] = 0;
        //     }
        // }



    }
};