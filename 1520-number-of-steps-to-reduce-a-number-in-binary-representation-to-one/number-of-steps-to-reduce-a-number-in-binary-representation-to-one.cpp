class Solution {
public:
    int numSteps(string str) {
        int res = 0, carry = 0;
        for (int i = str.length() - 1; i > 0; i--) {
            ++res;
            if (str[i] - '0' + carry == 1) {
                carry = 1;
                ++res;
            }
        }
        return res+carry;
    }
};