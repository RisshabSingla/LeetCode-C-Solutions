class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                open++;
            }else if(s[i] == ')'){
                ans = max(ans, open);
                open--;
            }
            // cout<<"open is: "<<open<<"\n";
        }
        return ans;
    }
};