class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int leftCount = 0;
        int rightCount = 0;
        stack<char> stack;

        // Pass 1
        for (char ch : str) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                stack.push(ch);
            }
        }

        string result = "";
        
        // Pass 2
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};