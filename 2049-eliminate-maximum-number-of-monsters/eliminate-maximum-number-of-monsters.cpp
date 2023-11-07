class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for(int i = 0; i<n; i++){
            time[i] = ((double)(dist[i]))/speed[i];
        }
        sort(time.begin(), time.end());
        double ready = 0.0;
        for(int i = 0; i<n; i++){
            if(time[i] <= ready){
                return i;
            }
            ready+= 1.0;
        }
        return n;

    }
};