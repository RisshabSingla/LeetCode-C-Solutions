class Solution {
public:
    int helper(string &s, string &t, int sindex, int tindex){
        if(tindex<0){
            return 1;
        }
        if(sindex <0){
            return 0;
        }

        if(s[sindex] == t[tindex]){
            return helper(s,t, sindex-1,tindex-1) + helper(s,t, sindex-1, tindex);
        }
        return helper(s,t, sindex-1, tindex);
    }

    int helperMemo(string &s, string &t, int sindex, int tindex, vector<vector<int>> &dp){
        if(tindex<0){
            return 1;
        }
        if(sindex <0){
            return 0;
        }

        if(dp[sindex][tindex]!= -1){
            return dp[sindex][tindex];
        }

        if(s[sindex] == t[tindex]){
            dp[sindex][tindex] =  helperMemo(s,t, sindex-1,tindex-1,dp) + helperMemo(s,t, sindex-1, tindex,dp);
            return dp[sindex][tindex];
        }

        dp[sindex][tindex] = helperMemo(s,t, sindex-1, tindex,dp);
        return dp[sindex][tindex]; 
    }

    int numDistinct(string s, string t) {
        // Approach 1: Brute Force : O(2^n)
        // int slen = s.length();
        // int tlen = t.length();
        // return helper(s, t, slen-1,tlen-1);

        // Approach 2: Memoization
        int slen = s.length();
        int tlen = t.length();
        vector<vector<int>> dp(slen+1, vector<int>(tlen+1, -1));
        return helperMemo(s, t, slen-1, tlen-1,dp);
        // return dp[slen][tlen];

    }
};