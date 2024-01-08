class Solution {
public:
    vector<vector<int>> arr;
    vector<pair<int,int>> ones;
    int rows;
    int cols;
    Solution(int m, int n) {
        rows = m;
        cols = n;
        arr.resize(m, vector<int>(n,0));
    }
    bool isPresent(int x, int y){
        for(int i = 0; i<ones.size(); i++){
            if(ones[i].first == x && ones[i].second == y){
                return true;
            }
        }
        return false;
    }
    vector<int> flip() {
        int x = rand() % rows;
        int y = rand() % cols;
        
        while(isPresent(x,y)){
            x = rand() % rows;
            y = rand() % cols;
        }
        ones.push_back({x,y});
        return {x,y};
    }
    
    void reset() {
        ones.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */