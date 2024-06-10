class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> pref(1002, 0);
        for(auto &i: trips){
            pref[i[1]+1]+= i[0];
            pref[i[2]+1]-= i[0];
        }
        for(int i = 1; i<=1001; i++){
            pref[i]+= pref[i-1];
            if(pref[i] > capacity){
                return false;
            }
        }
        // for(int i = 0; )
        return true;
    }
};