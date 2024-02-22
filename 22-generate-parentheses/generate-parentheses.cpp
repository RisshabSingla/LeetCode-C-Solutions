class Solution {
public:
    void recur(int n, int open, int close, vector<string>&ans, string& curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        if(open > n || close > n){
            return;
        }
        curr.push_back('(');
        recur(n, open+1, close, ans, curr);
        curr.pop_back();
        if(close<open){
            curr.push_back(')');
            recur(n, open, close+1, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        recur(n,0,0 ,ans, str);
        return ans;
    }
};