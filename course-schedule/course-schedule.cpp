class Solution {
public:
    bool dfs(vector<vector<int>>& prerequisites, vector<bool> &visited, vector<bool> &pathVisited, int edges, int node){
        visited[node] = true;
        pathVisited[node] = true;
        for(int i = 0; i<edges; i++){
            if(prerequisites[i][1] == node){
                int next_node = prerequisites[i][0];
                if(!visited[next_node]){
                    // visited[next_node] = true;
                    // pathVisited[next_node] = true;
                    bool a = dfs(prerequisites, visited, pathVisited, edges, next_node);
                    if(a == true){
                        // cycle present
                        return true;
                    }
                }
                if(pathVisited[next_node]){
                    // node encountered again in the same path
                    return true;
                }
            }
        }
        pathVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);    
        vector<bool> pathVisited(numCourses, false);
        int edges = prerequisites.size();
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                bool a = dfs(prerequisites, visited, pathVisited, edges, i);
                if(a == true){
                    // cycle is present
                    return false;
                }
            }
        }
        return true;
    }
};