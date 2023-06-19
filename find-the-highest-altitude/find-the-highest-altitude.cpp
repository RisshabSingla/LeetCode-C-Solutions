class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int max_altitude = 0;
        for(int i = 0; i<gain.size(); i++){
            altitude+=gain[i];
            max_altitude = max(max_altitude, altitude);
        }
        return max_altitude;
    }
};