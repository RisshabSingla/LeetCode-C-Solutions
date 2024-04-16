class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, int curr, vector<int> &path, int target){
        if(curr == target){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i<graph[curr].size(); i++){
            path.push_back(graph[curr][i]);
            dfs(graph, graph[curr][i], path, target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr;
        curr.push_back(0);
        int n = graph.size();
        dfs(graph, 0, curr, n-1);
        return ans;
    }
};