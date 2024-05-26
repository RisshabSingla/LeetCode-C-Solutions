class Solution {
public:
    int mod = 1e9+7;
    // map<vector<int>,int> dp;
    vector<vector<vector<int>>> dp;

    int calcAns(int days, int absent, int late){
        if(absent >= 2){
            return 0;
        }
        if(late >= 3){
            return 0;
        }
        if(days == 0){
            return 1;
        }
        if(dp[days][absent][late] != -1){
            return dp[days][absent][late];
        }
        int Absent = calcAns(days-1, absent+1, 0);
        int Late = calcAns(days-1, absent, late+1);
        int Present = calcAns(days-1, absent, 0);
        return dp[days][absent][late] = ((Absent + Late)%mod + Present)%mod;
    }
    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return calcAns(n, 0,0);
    }
};