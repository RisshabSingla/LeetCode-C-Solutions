class Solution {
public:
    void recursive(int low, int high, int number, vector<int>& ans) {
        // cout<<"Number is: "<<number<<"\n";
        if (low <= number && number <= high) {
            // cout<<"Pushing: "<<number<<"\n";
            ans.push_back(number);
        }
        if (number > high) {
            // cout<<"Returned false\n";
            return;
        }

        if (number % 10 == 9) {
            // cout<<"Returned false\n";
            return;
        }
        number = number * 10 + (number % 10 + 1);
        recursive(low, high, number, ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        // int num = low/pow(10,(log10(low)));
        // cout<<"NUm is: "<<num<<"\n";
        for (int i = 1; i < 10; i++) {
            // cout<<"Sending: "<<i<<"\n";
            recursive(low, high, i, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};