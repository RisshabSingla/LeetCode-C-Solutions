class Solution {
public:
    string makeGood(string& str) {
        // int slen = str.length();
        // while(true){
        //     bool change = false;
        //     for(int i = slen-1; i > 0; i--){
        //         if(str[i] == str[i-1] + 32 || str[i] + 32 == str[i-1]){
        //             str.erase(str.begin() + i - 1);
        //             str.erase(str.begin() + i - 1);
        //             slen-=2;
        //             change = true;
        //         }
        //     }
        //     if(!change){
        //         break;
        //     }
        // }
        // return str;

        stack<char> stk;
        
        for (char c : str) {
            if (!stk.empty() && abs(c - stk.top()) == 32) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;

    }
};