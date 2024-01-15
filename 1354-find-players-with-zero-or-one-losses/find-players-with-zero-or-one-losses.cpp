class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> won;
        unordered_map<int,int> lost;
        for(auto &i: matches){
            won[i[0]]++;
            lost[i[1]]++;
        }
        vector<vector<int>> ans(2, vector<int>());
        // vector<int> notLost;
        // vector<int> oneLost;
        for(auto i: won){
            if(lost.count(i.first) == 0){
                ans[0].push_back(i.first);
            }
        }
        for(auto i: lost){
            if(i.second == 1){
                ans[1].push_back(i.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};