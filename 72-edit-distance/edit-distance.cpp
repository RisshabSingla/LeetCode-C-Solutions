class Solution {
public:
    int dp[501][501];
    // int recursive(string &word1, string &word2, int index1, int index2, int &len1, int &len2){
    //     if(index1 == len1 && index2 == len2){
    //         return 0;
    //     }
    //     if(index1 == len1){
    //         return len2-index2;
    //     }
    //     if(index2 == len2){
    //         return len1-index1;
    //     }
    //     if(word1[index1] == word2[index2]){
    //         return recursive(word1, word2, index1+1, index2+1, len1, len2);
    //     }
    //     int insert = recursive(word1, word2, index1, index2+1, len1, len2);
    //     int del = recursive(word1, word2, index1+1, index2, len1, len2);
    //     int rep = recursive(word1, word2, index1+1, index2+1, len1, len2);
    //     return min({insert, del, rep}) + 1;
    // }

    int memo(string &word1, string &word2, int index1, int index2, int &len1, int &len2){
        if(index1 == len1 && index2 == len2){
            return 0;
        }
        if(index1 == len1){
            return len2-index2;
        }
        if(index2 == len2){
            return len1-index1;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(word1[index1] == word2[index2]){
            return memo(word1, word2, index1+1, index2+1, len1, len2);
        }
        int insert = memo(word1, word2, index1, index2+1, len1, len2);
        int del = memo(word1, word2, index1+1, index2, len1, len2);
        int rep = memo(word1, word2, index1+1, index2+1, len1, len2);
        return dp[index1][index2] =  min({insert, del, rep}) + 1;
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        // return recursive(word1, word2, 0,0, len1, len2);
        memset(dp, -1, sizeof(dp));
        return memo(word1, word2, 0,0, len1, len2);

    }
};