class Solution {
public:
    double calcSlope(vector<int>&a, vector<int>&b){
        double y = (double)a[1] - (double)b[1];
        double x = (double)a[0] - (double)b[0];
        double ans = y/x;
        return ans;
    }
    // static bool comp(vector<int>&a, vector<int>&b){
    //     if(a[0] == b[0]){
    //         return a[1] < b[1];
    //     }
    //     return a[0] < b[0];
    // }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1){
            return 1;
        }
        sort(points.begin(), points.end());
        int count = 0;
        for(int i = 0; i<n; i++){
            unordered_map<double,int> mp;
            for(int j = i; j<n; j++){
                double slope = calcSlope(points[i], points[j]);
                // cout<<slope<<"\n";
                mp[slope]++;
            }
            for(auto &i: mp){
                count = max(count, i.second);
            }
        }
        return count+1;
    }
};