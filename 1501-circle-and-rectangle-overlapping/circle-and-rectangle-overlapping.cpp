class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestX = max(x1, min(x2, xCenter));
        int nearestY = max(y1, min(y2, yCenter));
        int dist_x = nearestX - xCenter;
        int dist_y = nearestY - yCenter;
        int dist = (dist_x)*(dist_x) + (dist_y)*(dist_y);
        int rSquare = radius*radius;
        return dist <= rSquare;
    }
};