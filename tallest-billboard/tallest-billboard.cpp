class Solution {
public:
    int max_height;
    void helperRec(vector<int>&rods, int length1, int length2, int index, int size){
        if(index == size){
            if(length1 == length2){
                max_height = max(max_height, length1);
                return;
            }
            return;
        }
        // including the curr rod in length1
        helperRec(rods, length1 + rods[index], length2, index+1, size);
        // including the curr rod in length2
        helperRec(rods, length1 , length2 + rods[index], index+1, size);
        //including the curr rod in neither
        helperRec(rods, length1, length2, index+1, size);
    }

    int helperDP(vector<int>&rods, int diff, int index, vector<vector<int>> &dp, int size){
        if(index == size){
            if(diff == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[index][diff+5000] != -1){
            return dp[index][diff+5000];
        }

        int left = rods[index] + helperDP(rods, diff + rods[index], index+1, dp, size);
        int right = helperDP(rods, diff-rods[index], index+1, dp,size);
        int none = helperDP(rods, diff, index+1, dp,size);

        dp[index][diff+5000] = max({left, right, none});
        return dp[index][diff+5000];
    }

    int tallestBillboard(vector<int>& rods) {
        // max_height = 0;
        // int size = rods.size();
        // helperRec(rods, 0,0,0, size);
        // return max_height;

        int size = rods.size();
        vector<vector<int>>dp(size+1, vector<int> (10002,-1));
        // dp[0][0] = 0;
        
        return helperDP(rods, 0, 0, dp,size); 


    }
};