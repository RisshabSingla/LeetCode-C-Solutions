class Solution {
public:
    bool memo(string &s, string&p, int index1, int index2, int&slen, int &plen, vector<vector<int>> &dp){
        if(index1 == slen && index2 == plen){
            return true;
        }
        if(index1 > slen || index2 > plen){
            return false;
        }
        
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(p[index2] == '?'){
            return dp[index1][index2] = memo(s, p, index1+1, index2+1, slen, plen, dp);
        }
        if(p[index2] == '*'){
            bool a = memo(s, p, index1+1, index2, slen, plen, dp);
            bool b = memo(s, p, index1+1, index2+1, slen, plen,dp);
            bool c = memo(s, p, index1, index2+1, slen, plen,dp);
            return dp[index1][index2] = (a || b || c);
        }
        if(p[index2] == s[index1]){
            return dp[index1][index2] = memo(s, p, index1+1, index2+1, slen, plen,dp);
        }
        dp[index1][index2] = false;
        return false;
    }
    bool recursive(string &s, string&p, int index1, int index2, int&slen, int &plen){
        if(index1 == slen && index2 == plen){
            return true;
        }
        if(index1 > slen || index2 > plen){
            return false;
        }

        if(p[index2] == '?'){
            return recursive(s, p, index1+1, index2+1, slen, plen);
        }
        if(p[index2] == '*'){
            bool a = recursive(s, p, index1+1, index2, slen, plen);
            bool b = recursive(s, p, index1+1, index2+1, slen, plen);
            bool c = recursive(s, p, index1, index2+1, slen, plen);
            return a || b || c;
        }
        if(p[index2] == s[index1]){
            return recursive(s, p, index1+1, index2+1, slen, plen);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<int>> dp(slen+1, vector<int>(plen+1, -1));
        return memo(s, p, 0,0, slen, plen, dp);
    }
};