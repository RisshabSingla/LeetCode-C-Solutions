class Solution {
public:
    int recursive(vector<vector<int>> &books, int index, int n, int shelfWidth, int width, int height){
        if(index == n){
            return height;
        }
        int keep = INT_MAX;
        int skip = 0;
        if(width >= books[index][0]){
            int h = max(height, books[index][1]);
            keep = recursive(books, index+1, n, shelfWidth, width-books[index][0], h);
        }
        skip = recursive(books, index+1, n, shelfWidth, shelfWidth-books[index][0], books[index][1]) + height;
        return min(keep, skip);
    }

    int dp[1001][1001];
    int memo(vector<vector<int>> &books, int index, int n, int shelfWidth, int width, int height){
        if(index == n){
            return height;
        }
        if(dp[index][width] != -1){
            return dp[index][width];
        }
        int keep = INT_MAX;
        int skip = 0;
        if(width >= books[index][0]){
            int h = max(height, books[index][1]);
            keep = memo(books, index+1, n, shelfWidth, width-books[index][0], h);
        }
        skip = memo(books, index+1, n, shelfWidth, shelfWidth-books[index][0], books[index][1]) + height;
        return dp[index][width] =  min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        memset(dp, -1, sizeof(dp));
        return memo(books, 0, n, shelfWidth, shelfWidth, 0);
    }
};