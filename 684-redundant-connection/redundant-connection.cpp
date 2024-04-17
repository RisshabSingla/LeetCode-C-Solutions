class Solution {
public:
    int parent[1001];
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        // Path compression
        return parent[node] = findParent(parent[node]);
    }
    void Union(int a, int b){
        a = findParent(a);
        b = findParent(b);
        parent[a] = b;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i<1001; i++){
            parent[i] = i;
        }
        for(auto &i: edges){
            int a = findParent(i[0]);
            int b = findParent(i[1]);
            if(a == b){
                return i;
            }
            parent[a] = b;
        }
        return {};
    }
};