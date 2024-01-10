class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        int len = secret.length();
        unordered_map<char, int> freq;
        for (int i = 0; i < len ; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret[i] = 'X';
                guess[i] = 'X';
            } else {
                freq[secret[i]]++;
            }
        }

        for (int i = 0; i < len; i++) {
            if (guess[i] != 'X' && freq.count(guess[i]) && freq[guess[i]] > 0) {
                freq[guess[i]]--;
                cows++;
            }
        }
        return (to_string(bulls) + "A" + to_string(cows) + "B");
    }
};