class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int len = secret.length();
        // unordered_map<char, int> freq;
        vector<int> freq(10,0);
        for (int i = 0; i < len ; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret[i] = 'X';
                guess[i] = 'X';
            } else {
                freq[secret[i]-'0']++;
            }
        }   

        for (int i = 0; i < len; i++) {
            if (guess[i] != 'X' && freq[guess[i]-'0'] > 0) {
                freq[guess[i]-'0']--;
                cows++;
            }
        }
        return (to_string(bulls) + "A" + to_string(cows) + "B");
    }
};