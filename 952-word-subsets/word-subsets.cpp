class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq2(26, 0);
        for (auto& i : words2) {
            vector<int> freq(26, 0);
            for (char ch : i) {
                freq[ch - 'a']++;
            }
            for(int k = 0; k<26; k++){
                freq2[k] = max(freq2[k], freq[k]);
            }
        }
        vector<string> ans;
        for (auto& i : words1) {
            vector<int> freq(26, 0);
            for (char ch : i) {
                freq[ch - 'a']++;
            }
            bool equal = true;
            for (int k = 0; k < 26; k++) {
                if (freq2[k] > freq[k]) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};