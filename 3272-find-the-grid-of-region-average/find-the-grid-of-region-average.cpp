class Solution {
public:
    bool isValid(vector<vector<int>>& image,int x, int y,  int threshold){
        int dir_x[] = {-1, 1, 0, 0};
        int dir_y[] = { 0, 0, 1, -1};
        for(int i = 0; i<3;i++){
            for(int j = 0; j<3; j++){
                for(int k = 0; k<4; k++){
                    int new_x = x + i + dir_x[k];
                    int new_y = y + j + dir_y[k];
                    if(new_x >= x && new_x < x+3 && new_y>= y && new_y <y+3){
                        if(abs(image[new_x][new_y] - image[x + i][y + j]) > threshold){
                            return false;
                        }
                    }
                }
                
            }
        }
        return true;
        // vector<vector<bool>> visited(3, vector<bool>(3, false));
        // queue<pair<int,int>> q;
        // visited[0][0]  = true;
        // q.push({x,y});
        // while(!q.empty()){
        //     pair<int,int> p = q.front();
        //     q.pop();
        //     for(int i = 0; i<4; i++){
        //         int new_x = p.first+dir_x[i];
        //         int new_y = p.second+dir_y[i];
        //         if(new_x >= x && new_x < x+3 && new_y>= y && new_y <y+3){
        //             if(!visited[new_x-x][new_y-y]){
        //                 visited[new_x-x][new_y-y] = true;
        //                 if(abs(image[new_x][new_y] - image[p.first][p.second]) > threshold){
        //                     return false;
        //                 }
        //                 q.push({new_x, new_y});
        //             }
        //         }
        //     }
        // }
        // return true;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<vector<int>>> result(n, vector<vector<int>>(m, vector<int>(2,0)));
        for(int i = 0; i<=n-3; i++){
            for(int j = 0; j<=m-3; j++){
                if(isValid(image, i,j,threshold)){
                    int count = 0;
                    for(int a = 0; a<3; a++){
                        for(int b = 0; b<3; b++){
                             count+= image[i+a][j+b];
                        }
                    }
                    int num = count/9;
                    for(int a = 0; a<3; a++){
                        for(int b = 0; b<3; b++){
                             result[i+a][j+b][0] +=  num;
                            result[i+a][j+b][1]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(result[i][j][1] != 0){
                    image[i][j] = result[i][j][0]/result[i][j][1];
                }
            }
        }
        return image;
        
    }
};