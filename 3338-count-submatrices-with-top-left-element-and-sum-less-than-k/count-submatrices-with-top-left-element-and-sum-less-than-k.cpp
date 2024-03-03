class Solution {
public:
//     int recur(vector<vector<int>>& arr, int k, vector<vector<bool>> &visited, int n, int m, int sum , int x, int y){
//         if(x<0 || x>=n || y<0 || y>=m){
//             return 0;
//         }
//         int count = 0;
//         sum+= arr[x][y];
//         if(sum > k){
//             return 0;
//         }
//         if(sum < k){
//             count++;
//         }
//         visited[x][y] = true;
//         if(x+1< n && !visited[x+1][y]){
//             visited[x+1][y] = true;
//             count+= recur(arr, k, visited, n,m, sum, x+1, y);
//         }
        
//         if(y+1< m && !visited[x][y+1]){
//             visited[x][y+1] = true;
//             // sum+= arr[x][y+1];
//             count+= recur(arr, k, visited, n,m, sum, x, y+1);
//         }
//         cout<<"For x: "<<x<<" y: "<<y<<" count: "<<count<<"\n";
//         return count;
//     }
    
//     int recur(vector<vector<int>>& arr, int k, vector<vector<bool>> &visited, int n, int m, int sum , int x, int y){
        
//     }
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum(n, vector<int> (m, 0));
        int count = 0;
        sum[0][0] = grid[0][0];
        if(sum[0][0] <=k){
            count++;
        }
        for(int i = 1; i<m; i++){
            sum[0][i] = sum[0][i-1] +  grid[0][i];
            if(sum[0][i] <= k){
                count++;
            }
        }
        for(int i = 1; i<n; i++){
            sum[i][0] = sum[i-1][0] +  grid[i][0];
            if(sum[i][0] <= k){
                count++;
            }
        }
        
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + grid[i][j] - sum[i-1][j-1];
                if(sum[i][j] <= k){
                    count++;
                }
            }
        }
        
        // for(auto&i: sum){
        //     for(auto&j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        // int count = recur(grid, k, visited, n,m, 0, 0,0);
        return count;
    }
};