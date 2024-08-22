class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        long long power = 1;
        while (num > 0) {
            int last = num % 2;
            if (last == 0) {
                ans += power;
            }
            num = num / 2;
            power = power * 2;
        }
        return ans;
    }
};