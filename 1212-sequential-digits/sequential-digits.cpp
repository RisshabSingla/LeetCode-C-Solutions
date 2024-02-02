class Solution {
public:
    void recursive(int low, int high, int number, vector<int>& ans) {
        if (low <= number && number <= high) {
            ans.push_back(number);
        }
        if (number > high) {
            return;
        }

        if (number % 10 == 9) {
            return;
        }
        number = number * 10 + (number % 10 + 1);
        recursive(low, high, number, ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 10; i++) {
            recursive(low, high, i, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};