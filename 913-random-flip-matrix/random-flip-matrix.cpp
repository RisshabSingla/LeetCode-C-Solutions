class Solution {
public:
    set<pair<int,int>>ones;
    int rows;
    int cols;
    Solution(int m, int n) {
        rows = m;
        cols = n;
        ones.clear();
    }

    vector<int> flip() {
        int x = rand() % rows;
        int y = rand() % cols;
        
        while(ones.count({x,y})){
            x = rand() % rows;
            y = rand() % cols;
        }
        ones.insert({x,y});
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