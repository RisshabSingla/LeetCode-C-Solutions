class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        // vector<int> ans(n);
        // ans[0] = pref[0];
        int prev = pref[0];
        for(int i = 1; i<n; i++){
            int t = pref[i];
            pref[i] = pref[i] xor prev;
            prev = t;
        }
        return pref;
    }
};