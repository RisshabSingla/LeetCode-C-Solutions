class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int,int>> vc;
        for(int i = 0; i<n; i++){
            vc.push_back({heights[i], i});
        }
        sort(vc.begin(), vc.end(), greater<pair<int,int>>());
        vector<string> ans;
        for(int i = 0; i<n; i++){
            ans.push_back(names[vc[i].second]);
        }
        return ans;
    }
};