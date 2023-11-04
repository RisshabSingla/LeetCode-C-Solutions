class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // int lsize = left.size();
        // int rsize = right.size();
        // int ans = 0;
        // for(int i = 0; i<lsize; i++){
        //     ans = max(ans, left[i]);
        // }
        // for(int i = 0; i<rsize; i++){
        //     ans = max(ans, n-right[i]);
        // }
        // return ans;
        auto ans = 0;
        for (auto x: left) ans = max(ans, x);
        for (auto x: right) ans = max(ans, n - x);
        return ans;
    }
};