class TrieNode {
public:
    bool isEnding;
    unordered_map<int, TrieNode*> children;
    TrieNode() { isEnding = false; }
};

class Solution {
public:
    int dirX[4] = {-1, 0, 1, 0};
    int dirY[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, string& word, int index, int slen,
             int x, int y, vector<vector<bool>>& visited, int rows, int cols) {
        if (index == slen) {
            return true;
        }
        int dir_x[] = {-1, 0, 1, 0};
        int dir_y[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols) {
                continue;
            }
            if (!visited[new_x][new_y] && board[new_x][new_y] == word[index]) {
                visited[new_x][new_y] = true;
                bool a = dfs(board, word, index + 1, slen, new_x, new_y,
                             visited, rows, cols);
                if (a) {
                    return true;
                }
                visited[new_x][new_y] = false;
            }
        }
        return false;
    }
    bool findWord(vector<vector<char>>& board, string& word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(rows,
                                                 vector<bool>(cols, false));
                    visited[i][j] = true;
                    if (dfs(board, word, 1, word.length(), i, j, visited, rows,
                            cols)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void insertWord(TrieNode* root, string& str) {
        TrieNode* parent = root;
        for (int i = 0; i < str.length(); i++) {
            if (!parent->children.count(str[i])) {
                parent->children[str[i]] = new TrieNode();
            }
            parent = parent->children[str[i]];
        }
        parent->isEnding = true;
    }
    void dfs(vector<vector<char>>& board, TrieNode* root, string& curr, int i,
             int j, int rows, int cols, vector<vector<bool>>& visited,
             vector<string>& ans) {

        // cout<<"Curr is: "<<curr<<"\n";
        if (root->isEnding) {
            root->isEnding = false;
            ans.push_back(curr);
        }

        for (int k = 0; k < 4; k++) {
            int x = i + dirX[k];
            int y = j + dirY[k];
            if (x < 0 || x >= rows || y < 0 || y >= cols) {
                continue;
            }
            if (!visited[x][y] && root->children.count(board[x][y])) {
                visited[x][y] = true;
                curr.push_back(board[x][y]);
                dfs(board, root->children[board[x][y]], curr, x, y, rows, cols,
                    visited, ans);
                curr.pop_back();
                visited[x][y] = false;
            }
        }
    }
    vector<string> findAnsTrie(vector<vector<char>>& board,
                               vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& i : words) {
            insertWord(root, i);
        }
        vector<string> ans;
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(root->children.count(board[i][j])){
                    string curr = "";
                    curr+= board[i][j];
                    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                    visited[i][j] = true;
                    TrieNode* parent = root->children[board[i][j]];
                    dfs(board, parent, curr, i, j, rows, cols, visited, ans);
                }
            }
        }
        return ans;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& arr) {
        // unordered_set<string> words(arr.begin(), arr.end());
        // vector<string> ans;
        // for(auto i: words){
        //     if(findWord(board, i)){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        return findAnsTrie(board, arr);
    }
};