class Solution {
public:
    int dp[1001][1001];
    // int recursive(string &text1, string &text2, int index1, int index2, int &len1, int &len2){
    //     if(index1 == len1 || index2 == len2){
    //         return 0;
    //     }
    //     int a = 0;
    //     int b = 0;
    //     int c = 0;
    //     if(text1[index1] == text2[index2]){
    //         a = recursive(text1, text2, index1+1, index2+1, len1, len2) + 1;
    //     }
    //     b = recursive(text1, text2, index1+1, index2, len1, len2);
    //     c = recursive(text1, text2, index1, index2+1, len1, len2);
    //     return max({a,b,c});
    // }

    int memo(string &text1, string &text2, int index1, int index2, int &len1, int &len2){
        if(index1 == len1 || index2 == len2){
            return 0;
        }
        int a = 0;
        int b = 0;
        int c = 0;

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        if(text1[index1] == text2[index2]){
            a = memo(text1, text2, index1+1, index2+1, len1, len2) + 1;
        }
        b = memo(text1, text2, index1+1, index2, len1, len2);
        c = memo(text1, text2, index1, index2+1, len1, len2);
        return dp[index1][index2] = max({a,b,c});
    }


    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        // return recursive(text1, text2, 0,0, len1, len2);

        memset(dp, -1, sizeof(dp));
        return memo(text1, text2, 0,0, len1, len2);
    }
};