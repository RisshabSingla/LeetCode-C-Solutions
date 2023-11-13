class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        int slen = s.length();
        string all = "aeiouAEIOU";
        for (int i = 0; i<slen; i++) {
            if (all.find(s[i]) != string::npos) {
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end(), greater<char>());
        string result = "";
        int n_vowels = vowels.size();
        for (int i = 0; i<slen; i++) {
            if (all.find(s[i]) != string::npos) {
                result += vowels[n_vowels-1];
                // vowels.pop_back();
                n_vowels--;
            } else {
                result += s[i];
            }
        }
        return result; 
    }
};