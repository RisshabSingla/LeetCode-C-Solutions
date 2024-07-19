class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& arr) {
        int n  = arr.size();
        int m = arr[0].size();
        vector<int> mini(n, INT_MAX);
        vector<int> maxi(m, INT_MIN);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mini[i] = min(arr[i][j], mini[i]);
                maxi[j] = max(maxi[j], arr[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == mini[i] && arr[i][j] == maxi[j]){
                    ans.push_back(arr[i][j]);
                }
            }
        }
        return ans;


    }
};