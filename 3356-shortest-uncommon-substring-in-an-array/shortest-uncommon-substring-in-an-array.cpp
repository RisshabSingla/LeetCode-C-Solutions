class Solution {
public:
    bool isPossible(const string& str, vector<string>& arr, int index, int n,
                    vector<unordered_set<string>>& substrings) {
        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (i == index) {
                continue;
            }
            if (substrings[i].find(str) != substrings[i].end()) {
                return false;
            }
        }
        return true;
    }
    unordered_set<string> generateSubstrings(string& str) {
        unordered_set<string> st;
        int slen = str.length();
        for (int i = 0; i < slen; i++) {
            for (int j = i; j < slen; j++) {
                st.insert(str.substr(i, j - i + 1));
            }
        }
        return st;
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<unordered_set<string>> substring(n);
        for (int i = 0; i < n; i++) {
            substring[i] = generateSubstrings(arr[i]);
        }
        vector<string> ans(n, "");
        for (int i = 0; i < n; i++) {
            int slen = arr[i].length();
            for (auto& j : substring[i]) {
                if (isPossible(j, arr, i, n, substring)) {
                    if (ans[i] == "") {
                        ans[i] = j;
                    } else if (ans[i].length() == j.length()) {
                        if (j < ans[i]) {
                            ans[i] = j;
                        }
                    } else if (ans[i].length() > j.length()) {
                        ans[i] = j;
                    }
                }
            }
        }
        return ans;
    }
};