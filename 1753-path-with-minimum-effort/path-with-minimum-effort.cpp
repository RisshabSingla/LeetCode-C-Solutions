class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<vector<int>>& heights, int x, int y, int diff, vector<vector<bool>> &visited, int rows, int cols){
        // cout<<"Curr x: "<<x<<" y: "<<y<<" diff: "<<diff<<endl;
        if(diff>=ans){
            // cout<<"Greater"<<endl;
            return;
        }
        
        if(x == rows-1 && y == cols-1){
            ans = min(ans, diff);
            // cout<<"new ans: "<<ans<<endl;
            // cout<<endl;
            return;
        }
        
        int dir_x[] = {-1, 1, 0, 0};
        int dir_y[] = {0, 0, -1, 1};
        visited[x][y] = true;
        for(int i = 0; i<4; i++){
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x >=0 && new_x<rows && new_y>=0 && new_y<cols){
                if(!visited[new_x][new_y]){
                    int new_diff = max(diff, abs(heights[new_x][new_y]-heights[x][y]));
                    helper(heights, new_x, new_y, new_diff, visited, rows, cols);
                }
            }
        }
        visited[x][y] = false;

    }

    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y,int diff, int rows, int cols){
        
        if(x == rows-1 && y == cols-1){
            return true;
        }

        int dir_x[] = {-1, 1, 0, 0};
        int dir_y[] = {0, 0, -1, 1};
        visited[x][y] = true;
        for(int i = 0; i<4; i++){
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if(new_x >=0 && new_x<rows && new_y>=0 && new_y<cols){
                if(!visited[new_x][new_y]){
                    int new_diff = abs(heights[new_x][new_y]-heights[x][y]);
                    if(new_diff<=diff){
                        bool a = dfs(heights, visited, new_x, new_y, diff, rows, cols);
                        if(a){
                            return true;
                        }
                    }
                }
            }
        }
        // visited[x][y] = false;
        return false;
        
    }

    bool checkValid(vector<vector<int>>& heights, int diff, int rows, int cols){
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        return dfs(heights, visited, 0, 0, diff, rows, cols);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        // Method 1: Using recursion
        // int rows = heights.size();
        // int cols = heights[0].size();
        // if(rows == 1 && cols == 1){
        //     return 0;
        // }
        // vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        // helper(heights,0,0, INT_MIN, visited, rows, cols);
        // return ans;

        // Method 2: Using Binary Search
        int rows = heights.size();
        int cols = heights[0].size();

        if(rows == 1 && cols == 1){
            return 0;
        }

        int low = 0;
        int high = 1000004;
        int ans = INT_MAX;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            cout<<"Checking for: "<<mid;
            if(checkValid(heights, mid, rows, cols)){
                cout<<" Valid"<<endl;
                ans = min(ans, mid);
                high = mid-1;
            }else{
                cout<<" Invalid"<<endl;
                low = mid+1;
            }
        }   
        return low;



    }
};