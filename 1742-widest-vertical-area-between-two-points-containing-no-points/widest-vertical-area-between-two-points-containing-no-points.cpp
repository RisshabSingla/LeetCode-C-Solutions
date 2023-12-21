class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int max_area = 0;
        for(int i = 1; i<points.size(); i++){
            int area = points[i][0] - points[i-1][0];
            max_area = max(max_area, area);
        }
        return max_area;
    }
};