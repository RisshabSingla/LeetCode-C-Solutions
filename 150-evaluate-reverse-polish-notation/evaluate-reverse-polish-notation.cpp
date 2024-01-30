class Solution {
public:
    int convert(string &str){
        int ans = 0;
        for(int i = 0; i<str.length(); i++){
            ans = ans*10 + (str[i]-'0');
        }
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0; i<tokens.size(); i++){
            if(isdigit(tokens[i][0])){
                int a = convert(tokens[i]);
                stk.push(a);
                // cout<<"Pushing: "<<a<<"\n";
            }else if(tokens[i][0] == '-' && tokens[i].length() > 1){
                string str = tokens[i].substr(1);
                int a = convert(str);
                stk.push(-a);
                // cout<<"Pushing: "<<-a<<"\n";
            }else{
                int first = stk.top();
                // cout<<"first: "<<first<<"\n";
                stk.pop();
                int second = stk.top();
                // cout<<"second: "<<second<<"\n";
                stk.pop();
                int ans = -1;
                if(tokens[i] == "+"){
                    ans = first+second;
                }else if(tokens[i] == "-"){
                    ans = (second-first);
                }else if(tokens[i] == "*"){
                    ans = (first*second);
                }else {
                    ans = (second/first);
                }
                stk.push(ans);
                // cout<<"Pushed "<<ans<<"\n";
            }
        }
        // cout<<"Ans is: "<<stk.top()<<"\n";
        return stk.top();
    }
    // "10","6","9","3","+","-11","*","/","*","17","+","5","+"]
};