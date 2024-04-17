class Solution {
public:
    int parent[int(1e5 + 2)];
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        int size = arr.size();
        if(size < n-1){
            return -1;
        }
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        int extra = 0;
        for(auto &i: arr){
            int a = findParent(i[0]);
            int b = findParent(i[1]);
            if(a == b){
                extra++;
            }
            parent[a] = b;
        }
        int components = 0;
        for(int i = 0; i<n; i++){
            if(parent[i] == i){
                components++;
            }
        }
        // cout<<"Extra: "<<extra<<" comp: "<<components<<"\n";
        return components-1;
    }
};