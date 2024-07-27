class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> minCosts(26, vector<long long>(26, LLONG_MAX));
        int n = cost.size();
        for (int i = 0; i < n; i++) {
            minCosts[original[i] - 'a'][changed[i] - 'a'] = min((long long)(cost[i]), minCosts[original[i] - 'a'][changed[i] - 'a']);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (minCosts[i][k] != LLONG_MAX &&
                        minCosts[k][j] != LLONG_MAX) {
                        minCosts[i][j] = min(minCosts[i][j],
                                             minCosts[i][k] + minCosts[k][j]);
                    }
                }
            }
        }


        // for (auto i : minCosts) {
        //     for (auto j : i) {
        //         if (j == LLONG_MAX) {
        //             cout << -1 << " ";
        //         } else {
        //             cout << j << " ";
        //         }
        //     }
        //     cout << "\n";
        // }

        long long ans = 0;

        for(int i = 0; i<source.length(); i++){
            if(source[i] == target[i]){
                continue;
            }
            if(minCosts[source[i]-'a'][target[i]-'a'] == LLONG_MAX){
                return -1;
            }
            ans+= minCosts[source[i]-'a'][target[i]-'a'];
        }
        return ans;

        // return 0;
    }
};