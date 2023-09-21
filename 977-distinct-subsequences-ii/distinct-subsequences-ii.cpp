class Solution {
public:
    void helper(string str, int index, int slen, set<string> &subseq, 
        int &count, string curr ){
        if(index == slen){
            if(subseq.count(curr) == 0){
                count++;
                count = count%(int)(1e9+7);
                subseq.insert(curr);
            }
            return;
        }
        helper(str, index+1, slen,subseq,count, curr);
        helper(str, index+1, slen,subseq,count, curr+str[index]);
    }
    int distinctSubseqII(string s) {
        // Approach 1: Brute Force: O(2^n)
        // int count = 0;
	    // set<string> subseq;
	    // helper(str, 0, str.length(), subseq,count, "");
	    // return count; 

        // Approach 2: Using DP
        
        int slen = s.length();
        vector<long long> dp(slen+1, 0);
        vector<int> lastOcc(26,-1);
        dp[0] = 1;
        const int mod = 1e9 +7;
        for(int i = 1; i<=slen; i++){
            if(lastOcc[s[i-1]-'a'] != -1){
                int pos = lastOcc[s[i-1]-'a'];
                // dp[i] = ((dp[i-1]+dp[i-1])%mod - dp[pos-1])%mod;
                dp[i] = (dp[i-1] + (dp[i-1] - dp[pos-1])%mod)%mod;
                // we will remove the repeating characters
            }else{
                dp[i] = ((dp[i-1]%mod)+dp[i-1])%mod;
                // twice bcoz 
                // Once not taking
                // Once taking
            }
            if(dp[i]<0){
                dp[i]+=mod;
            }
            dp[i]%=mod;
            lastOcc[s[i-1]-'a'] = i;
        }
        
        return ((dp[slen]-1)+mod)%mod;

    }
};