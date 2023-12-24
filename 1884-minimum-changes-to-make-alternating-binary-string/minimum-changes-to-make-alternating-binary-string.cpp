class Solution {
public:
    int countOperations(string &str, char prev){
        int count = 0;
        for (int i = 1; i < str.length(); i++) {
            if (str[i] == prev) {
                count++;
                prev = prev == '0' ? '1' : '0';
            } else {
                prev = str[i];
            }
        }
        return count;
    }
    int minOperations(string str) {
        int c1 = countOperations(str, str[0]);
        int c2 = countOperations(str, str[0] == '1' ? '0' : '1') + 1;
        return min(c1,c2);
    }
};