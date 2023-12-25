class Solution {
public:
    int numDecodings(string str) {
        int slen = str.length();
        vector<int> dp(slen+1);
        dp[0]=1;
        if(str[0] == '0'){
            dp[1] = 0;
        }else{
            dp[1] = 1;
        }
        for(int i = 2; i<=slen; i++){
            int one = 0;
            int two = 0;
            if(str[i-1] != '0'){
                one = dp[i-1];
            }
            if(stoi(str.substr(i-2,2)) <= 26  && 
                stoi(str.substr(i-2,2)) > 0 && 
                str[i-2] != '0'){
                    two = dp[i-2];
            }
            dp[i] = one+two;
        }
        return dp[slen];
    }
};