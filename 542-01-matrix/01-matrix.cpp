class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {


        // Approach 1: Using vectors
        // int rows = mat.size();
        // int cols = mat[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // vector<vector<int>> ans(rows, vector<int>(cols, -1));
        // vector<pair<int,int>> dist;

        // for(int i = 0; i<rows; i++){
        //     for(int j = 0; j<cols; j++){
        //         if(mat[i][j] == 0){
        //             dist.push_back({i,j});
        //             visited[i][j] = true;
        //             ans[i][j] = 0;
        //         }
        //     }
        // }

        // int distance = 1;
        // int dir_x[] = {0, 1, -1, 0};
        // int dir_y[] = {1, 0, 0, -1};

        // vector<pair<int,int>> pts;
        // while(dist.size()!= 0){
        //     for(int i = 0; i<dist.size(); i++){
        //         for(int k = 0; k<4; k++){
        //             int new_x = dist[i].first + dir_x[k];
        //             int new_y = dist[i].second + dir_y[k];
        //             if(new_x>= 0 && new_x<rows && new_y >= 0 && new_y < cols && !visited[new_x][new_y]){
        //                 visited[new_x][new_y] = true;
        //                 pts.push_back({new_x, new_y});
        //                 ans[new_x][new_y] = distance;
        //             }
        //         }
        //     }
        //     dist = pts;
        //     pts.clear();
        //     distance++;
        // }
        // return ans;


        // Approach 2: Using queue
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }

        int dir_x[] = {0, 1, -1, 0};
        int dir_y[] = {1, 0, 0, -1};
        while(!q.empty()){
            pair<pair<int,int>,int> piii = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int new_x = piii.first.first + dir_x[k];
                int new_y = piii.first.second + dir_y[k];
                if(new_x>= 0 && new_x<rows && new_y >= 0 && new_y < cols && !visited[new_x][new_y]){
                    visited[new_x][new_y] = true;
                    q.push({{new_x, new_y}, piii.second+1});
                    ans[new_x][new_y] = piii.second +1;
                }
            }
        }
        return ans;

    }
};