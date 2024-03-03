class Solution {
public:
    int countWays(vector<vector<int>>& arr, int n, int numY, int numO){
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        for(int i = 0; i<n/2; i++){
            visited[i][i] = true;
            if(arr[i][i] != numY){
                count++;
            }
            visited[i][n-i-1] = true;
            if(arr[i][n-i-1] != numY){
                count++;
            }
            
        }
        for(int i = n/2; i<n; i++){
            visited[i][n/2] = true;
            if(arr[i][n/2] != numY){
                count++;
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                if(!visited[i][j] && arr[i][j] != numO){
                    count++;
                }
            }
        }
        return count;
        
    }
    int minimumOperationsToWriteY(vector<vector<int>>& arr) {
        // vector<int> countY(3, 0);
        // vector<int> countOther(3, 0);
        int n = arr.size();
        
        
        int count = INT_MAX;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(i == j){
                    continue;
                }
                int c = countWays(arr, n, i, j);
                count = min(c, count);
            }
        }
        return count;
        
        // for(int i = 0; i<n/2; i++){
        //     visited[i][i] = true;
        //     countY[arr[i][i]]++;
        //     visited[i][n-i-1] = true;
        //     countY[arr[i][n-i-1]]++;
        // }
        // for(int i = n/2; i<n; i++){
        //     visited[i][n/2] = true;
        //     countY[visited[i][n/2]]++;
        // }
        
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<n;j++){
//                 if(!visited[i][j]){
//                     countOther[arr[i][j]]++;
//                 }
//             }
//         }
        
        
//         int YZeros = countY[0];
//         int YOnes = countY[1];
//         int YTwos = countY[2];
        
//         int OtherZeros = countOther[0];
//         int OtherOnes = countOther[1];
//         int OtherTwos = countOther[2];
        
//         int maxiY = max({YZeros, YOnes, YTwos});
//         int maxiO = max({OtherZeros, OtherOnes, OtherTwos});
        
        // if()
    }
};