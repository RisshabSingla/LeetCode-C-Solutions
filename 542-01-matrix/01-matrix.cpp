class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // queue<pair<int,int>> q;
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        vector<pair<int,int>> dist;

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(mat[i][j] == 0){
                    dist.push_back({i,j});
                    visited[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }

        int distance = 1;
        int dir_x[] = {0, 1, -1, 0};
        int dir_y[] = {1, 0, 0, -1};

        // cout<<"Dist is: "<<endl;
        // for(auto i: dist){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<endl;
        vector<pair<int,int>> pts;
        while(dist.size()!= 0){
            // cout<<"Starting"<<endl;
            for(int i = 0; i<dist.size(); i++){
                // pair<int,int> p = dis[i];
                for(int k = 0; k<4; k++){
                    int new_x = dist[i].first + dir_x[k];
                    int new_y = dist[i].second + dir_y[k];
                    if(new_x>= 0 && new_x<rows && new_y >= 0 && new_y < cols && !visited[new_x][new_y]){
                        visited[new_x][new_y] = true;
                        pts.push_back({new_x, new_y});
                        ans[new_x][new_y] = distance;
                    }
                }
            }

            // cout<<"Pts is: "<<endl;
            // for(auto i: pts){
            //     cout<<i.first<<" "<<i.second<<endl;
            // }
            // cout<<endl;
            dist = pts;
            pts.clear();
            distance++;
            // cout<<"Fine"<<endl;
            // dist.clear();
            // for(auto i: pts){
            //     dist.push_back(i);
            // }
        }
        return ans;

    }
};