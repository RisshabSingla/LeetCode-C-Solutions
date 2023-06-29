class Solution {
public:
    bool keyPresent(char ch , string str){
        for(int i = 0; i<str.length(); i++){
            if(str[i] == ch){
                return true;
            }
        }
        return false;
    }



    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int start_x = -1;
        int start_y = -1;
        int keyCount = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '@'){
                    start_x = i;
                    start_y = j;
                }
                if(grid[i][j] >= 'a' && grid[i][j] <='f'){
                    keyCount++;
                }
            }
        }


        queue< pair< pair<int,int>, string>> q;
        q.push({{start_x, start_y},""});

        unordered_set<string> isVisited;
        int moves = 0;
        while(!q.empty()){
            int length = q.size();

            for(int i = 0;i<length;i++){
                auto data = q.front();
                q.pop();
                int curr_x = data.first.first;
                int curr_y = data.first.second;
                string keys = data.second;
                if(keys.size() == keyCount){
                    return moves;
                }

                string key = to_string(curr_x) + ":" + to_string(curr_y) + ":" + keys;
                

                if(isVisited.find(key) != isVisited.end()){
                    continue;
                }

                isVisited.insert(key);

                vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
                for(int i = 0; i<4; i++){
                    int new_x = curr_x + direction[i][0];
                    int new_y = curr_y + direction[i][1];
                    if(new_x <0 || new_x >=n || new_y<0 || new_y>=m || grid[new_x][new_y] == '#'){
                        continue;
                    }
                    
                    char ch = grid[new_x][new_y];
                    if(ch >='A' && ch <='F' && keyPresent(ch+32, keys)){
                        q.push({{new_x, new_y}, keys});
                    }else if(ch == '.' || ch == '@'){
                        q.push({{new_x, new_y}, keys});
                    }else if(ch >='a' && ch <='f'){
                        if(keyPresent(ch, keys)){
                            q.push({{new_x, new_y}, keys});
                        }else{
                            q.push({{new_x, new_y}, keys + ch});
                        }
                    }


                }


            }
            moves++;
        }
        return -1;

    }
};




