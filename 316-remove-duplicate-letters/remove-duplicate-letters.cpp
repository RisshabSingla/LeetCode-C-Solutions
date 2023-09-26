class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }

        stack<char> stk;
        vector<bool> inStack(26, false);
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']--;
            if(inStack[s[i]-'a']){
                continue;
            }

            while(!stk.empty() && s[i]<stk.top() && freq[stk.top() - 'a'] > 0){
                inStack[stk.top()-'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            inStack[s[i]-'a'] = true;
        }

        string ans = "";
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};