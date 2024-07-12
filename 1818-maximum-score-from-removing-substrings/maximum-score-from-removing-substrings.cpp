class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string round;
        string other;
        int round_score;
        int other_score;

        if (y > x) {
            round = "ba";
            round_score = y;
            other = "ab";
            other_score = x;
        } else {
            round = "ab";
            round_score = x;
            other = "ba";
            other_score = y;
        }

        vector<char> stack;
        for (char ch : s) { 
            if (ch == round[1] && !stack.empty() && stack.back() == round[0]) {
                ans += round_score;
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }

        vector<char> new_stack;
        for (char ch : stack) {  
            if (ch == other[1] && !new_stack.empty() && new_stack.back() == other[0]) {
                ans += other_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }

        return ans;
    }
};