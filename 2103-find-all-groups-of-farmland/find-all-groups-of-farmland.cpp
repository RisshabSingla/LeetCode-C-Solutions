class Solution {
public:
    int dirX[2] = {0,1};
    int dirY[2] = {1,0};
    vector<int> BFS(vector<vector<int>>& arr, int& i, int& j, int& n, int& m){
        queue<pair<int,int>> q;
        q.push({i,j});
        arr[i][j] = INT_MAX;
        vector<int> ans = {i,j};
        pair<int,int> prev;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            prev = p;
            for(int k = 0; k<2; k++){
                int x = p.first + dirX[k];
                int y = p.second + dirY[k];
                if(x >= 0 && x< n && y < m && y>=0 && arr[x][y] == 1){
                    arr[x][y] = INT_MAX;
                    q.push({x,y});
                }
            }
        }
        ans.push_back(prev.first);
        ans.push_back(prev.second);
        return ans;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(land[i][j] == 1){
                    vector<int> arr = BFS(land, i, j, n,m);
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
};