class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> newGrid(n, vector<int>(m, 0));
        while(true){
            // cout<<"Starting\n";
            // for(int i = 0; i<n; i++){
            //     for(int j = 0; j<m; j++){
            //         newGrid[i][j] = grid[i][j];
            //     }
            // }
            // cout<<"Count is: "<<count<<"\n";
            newGrid = grid;
            bool changed = false;
            count++;
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    if(grid[i][j] == 2){
                        if(i-1 >= 0 && grid[i-1][j] != 0 && grid[i-1][j] != 2){
                            newGrid[i-1][j] = 2;
                            changed = true;
                        }
                        if(j-1 >= 0 && grid[i][j-1] != 0 && grid[i][j-1] != 2){
                            newGrid[i][j-1] = 2;
                            changed = true;
                        }

                        if(i+1 < n && grid[i+1][j] != 0 && grid[i+1][j] != 2){
                            newGrid[i+1][j] = 2;
                            changed = true;
                        }

                        if(j+1 < m && grid[i][j+1] != 0 && grid[i][j+1] != 2){
                            newGrid[i][j+1] = 2;
                            changed = true;
                        }
                    }
                }
            }
            // cout<<"Grid was:\n";
            // for(auto &i: grid){
            //     for(auto &j: i){
            //         cout<<j<<" ";
            //     }
            //     cout<<"\n";
            // }
            // cout<<"New Grid is:\n";
            // for(auto &i: newGrid){
            //     for(auto &j: i){
            //         cout<<j<<" ";
            //     }
            //     cout<<"\n";
            // }
            // cout<<"Changed is: "<<changed<<"\n";
            if(!changed){
                // cout<<"Breaking:\n";
                break;
            }
            grid = newGrid;
            // for(int i = 0; i<n; i++){
            //     for(int j = 0; j<m; j++){
            //         grid[i][j] = newGrid[i][j];
            //     }
            // }
            // grid = newGrid;
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count-1;
    }
};