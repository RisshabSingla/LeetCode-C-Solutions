class Solution {
public:
    string reverseParentheses(string str) {
        stack<char>stk;
        for(char ch: str){
            if(ch == ')'){
                queue<char> q;
                while(stk.top() != '('){
                    q.push(stk.top());
                    stk.pop();
                }
                stk.pop();
                while(!q.empty()){
                    stk.push(q.front());
                    q.pop();
                }
            }else{
                stk.push(ch);
            }   
        }
        string ans = "";
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};