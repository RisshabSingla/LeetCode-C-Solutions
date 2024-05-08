class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> s(score.size());
        for(int i = 0; i<score.size(); i++){
            s[i] = score[i];
        }
        sort(s.begin(), s.end(), greater<int>());
        map<int, string> mapping;
        mapping[s[0]] = "Gold Medal";
        if(score.size() > 1){
            mapping[s[1]] = "Silver Medal";
        }
        if(score.size() > 2){
            mapping[s[2]] = "Bronze Medal";
        }
        for(int i = 3; i<score.size(); i++){
            string rank = to_string(i+1);
            mapping[s[i]] = rank;
        }

        vector<string> ans(score.size());
        for(int i =0; i<score.size(); i++){
            ans[i] = mapping[score[i]];
        }
        return ans;
    }
};