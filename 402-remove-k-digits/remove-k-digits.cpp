class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        
        string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        reverse(result.begin(), result.end());
        
        int index = -1;
        for(int i = 0; i<result.length(); i++){
            if(result[i] != '0'){
                index = i;
                break;
            }
        }
        if(index == -1){
            return "0";
        }
        return result.substr(index);
    }
};