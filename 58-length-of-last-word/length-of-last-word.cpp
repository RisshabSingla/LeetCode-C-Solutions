class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        bool first = true;
        int end = -1;
        int start = -1;
        for (int i = length - 1; i >= 0; i--) {
            if (isalpha(s[i]) && first) {
                first = false;
                end = i;
            }
            if (end != -1 && s[i] == ' ') {
                start = i;
                break;
            }
        }
        return (end - start);
    }
};