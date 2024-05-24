class Solution {
public:
    int a[26], b[26], ans = 0;
    void solve(int index, vector<string>& words, vector<int>& score) {
        if (index == words.size()) {
            int sc = 0;
            for (int i = 0; i < 26; i++) {
                if (b[i] > a[i]) {
                    return;
                }
                sc += score[i] * b[i];
            }
            ans = max(ans, sc);
            return;
        }
        solve(index + 1, words, score);
        for (auto i : words[index])
            b[i - 'a']++;
        solve(index + 1, words, score);
        for (auto i : words[index])
            b[i - 'a']--;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        for (auto i : letters)
            a[i - 'a']++;
        solve(0, words, score);
        return ans;
    }
};