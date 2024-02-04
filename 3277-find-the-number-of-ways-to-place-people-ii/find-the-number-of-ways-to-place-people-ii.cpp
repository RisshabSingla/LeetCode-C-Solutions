class Solution {
public:
    bool valid(vector<vector<int>>& points, int ch, int ta, int n) {
        // cout<<"Ch is: "<<ch<<" ta is: "<<ta<<"\n";
        if (points[ta][0] < points[ch][0] || points[ch][1] < points[ta][1]) {
            // cout<<"Returning for start\n";
            return false;
        }
        bool flag = true;
        int start_x = min(points[ch][0], points[ta][0]);
        int finish_x = max(points[ch][0], points[ta][0]);
        int start_y = min(points[ch][1], points[ta][1]);
        int finish_y = max(points[ch][1], points[ta][1]);

        for (int i = 0; i < n; i++) {
            if (i == ch || i == ta) {
                continue;
            }
            // if(start_x <= points[i][0] && points[i][0] <= finish_x){
            //     cout<<"Returning from x: "<<i<<"\n";
            //     return false;
            // }
            // if(start_y <= points[i][1] && points[i][1] <= finish_y){
            //     cout<<"Returning from y: "<<i<<"\n";
            //     return false;
            // }

            if (start_y <= points[i][1] && points[i][1] <= finish_y &&
                start_x <= points[i][0] && points[i][0] <= finish_x) {
                return false;
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (valid(points, i, j, n)) {
                    count++;
                }
            }
        }
        return count;
    }
};