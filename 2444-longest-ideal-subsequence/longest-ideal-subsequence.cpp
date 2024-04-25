class Solution {
public:
    int dp[int(1e5+10)][27];
    int recursive(string&str, int index, int prev, int slen, int k){
        if(index == slen){
            return 0;
        }
        if(prev == 0 && dp[index][0] != -1){
            return dp[index][0];
        }
        if(prev != 0 &&  dp[index][prev-'a'+1] != -1){
            return dp[index][prev-'a'+1];
        }
        int a = 0;
        // cout<<"str[index]"<<str[index]<<" prev: "<<prev<<"\n";
        if(prev == 0 || abs(str[index] - prev) <= k){
            // cout<<"Inside\n";
            a = recursive(str, index+1, str[index], slen, k) + 1;
        }
        int ans = max(a, recursive(str, index+1, prev, slen, k));
        if(prev == 0){
            dp[index][prev] = ans;
        }else{
            dp[index][prev-'a' + 1] = ans;
        }
        return ans;
    }
    int longestIdealString(string str, int k) {
        memset(dp, -1 , sizeof(dp));
        return recursive(str, 0, 0, str.length(), k); 
    }
};