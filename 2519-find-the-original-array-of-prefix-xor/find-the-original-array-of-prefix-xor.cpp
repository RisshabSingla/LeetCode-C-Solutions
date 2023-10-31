class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        int num = pref[0];
        // int prev = pref[0];
        for(int i = 1; i<n; i++){
            ans[i] = pref[i] xor pref[i-1];
        }
        return ans;
    }
};