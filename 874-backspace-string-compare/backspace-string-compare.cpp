class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1;
        // return false;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '#'){
                if(!stk1.empty()){
                    stk1.pop();
                }
            }else{
                stk1.push(s[i]);
            }
        }
        stack<char> stk2;
        for(int i = 0; i<t.length(); i++){
            if(t[i] == '#'){
                if(!stk2.empty()){
                    stk2.pop();
                }
            }else{
                stk2.push(t[i]);
            }
        }

        if(stk1.size() != stk2.size()){
            return false;
        }

        while(!stk1.empty()){
            if(stk1.top() != stk2.top()){
                return false;
            }
            stk1.pop();
            stk2.pop();
        }
        return true;
        
    }
};