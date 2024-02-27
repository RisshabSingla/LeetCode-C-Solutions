class Solution {
public:
    int num_points;
    vector<int> cumulative_count;
    vector<vector<int>> rects;
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        num_points = 0;
        for(vector<int>&a: rects){
            num_points += (a[2]-a[0]+1)*(a[3]-a[1]+1);
            cumulative_count.push_back(num_points);
        }
    }
    
    vector<int> pick() {
        int index = rand() % num_points;
        int i = upper_bound(cumulative_count.begin(), cumulative_count.end(), index) - cumulative_count.begin();        
        vector<int> &a = rects[i];
        int x = a[2]-a[0]+1;
        int y = a[3]-a[1]+1;
        int total = x*y;
        int start = cumulative_count[i] - total;
        int offset = index- start;
        return {a[0]+offset%x , a[1]+offset/x};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */