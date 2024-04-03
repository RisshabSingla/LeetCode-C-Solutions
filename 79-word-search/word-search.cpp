class Solution {
public:
    int noRows;
    int noCols;
    bool checkValid(vector<vector<char>>& board, int index, int row, int col, vector<vector<bool>> &used, string&word){
        // cout<<"Inside check valid for i: "<<row<<" j: "<<col<<endl;
        if(index == word.length()){
            return true;
        }
        if(row<0 || col <0 || row==noRows || col==noCols){
            return false;
        }
        used[row][col] = true;
        if(col+1 <noCols && board[row][col+1] == word[index] && used[row][col+1] == false){
            if(checkValid(board, index+1, row, col+1, used, word)){
                return true;
            }
        }

        if(row +1 <noRows && board[row+1][col] == word[index] && used[row+1][col] == false){
            if(checkValid(board, index+1, row+1, col, used, word)){
                return true;
            }
        }
        if(row-1>-1 && board[row-1][col] == word[index] && used[row-1][col] == false){
            if(checkValid(board, index+1, row-1, col, used, word)){
                return true;
            }
        }
        if(col-1>-1 && board[row][col-1] == word[index] && used[row][col-1] == false){
            if(checkValid(board, index+1, row, col-1, used, word)){
                return true;
            }
        }
        used[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int nRows = board.size();
        int nCols = board[0].size();
        noRows = nRows;
        noCols = nCols;
        vector<vector<bool>> used(nRows, vector<bool>(nCols, false));

        for(int i =0; i<nRows; i++){
            for(int j = 0; j<nCols; j++){
                if(board[i][j] == word[0]){
                    if(checkValid(board, 1, i,j, used, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};