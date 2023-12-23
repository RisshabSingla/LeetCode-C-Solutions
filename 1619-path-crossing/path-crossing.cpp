class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visited;
        visited.insert({0,0});
        int x = 0;
        int y = 0;
        for(int i =0; i<path.length(); i++){
            if(path[i] == 'N'){
                ++y;
            }else if(path[i] == 'E'){
                --x;
            }else if(path[i] == 'W'){
                ++x;
            }else{
                --y;
            }
            if(visited.count({x,y})){
                return true;
            }
            visited.insert({x,y});
        }
        return false;
    }
};