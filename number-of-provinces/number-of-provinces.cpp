class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int index, int size){
        
        for(int i = 0; i<size; i++){
            if(isConnected[index][i] == 1 && visited[i] == false){
                visited[i] = true;
                dfs(isConnected, visited, i, size);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> visited(size, false);
        int count = 0;

        for(int i = 0; i<size; i++){
            if(visited[i] == false){
                dfs(isConnected, visited, i,size);
                count++;
            }
        }
        return count;
    }
};