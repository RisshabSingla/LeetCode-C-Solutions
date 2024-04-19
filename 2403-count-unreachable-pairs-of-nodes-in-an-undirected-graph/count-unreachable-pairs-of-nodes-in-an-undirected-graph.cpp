class Solution {
public:
    int findParent(int node, vector<int>&parent){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }
    void traverse(int i, unordered_map<int, vector<int>> &mp, vector<int>&parent){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &i: mp[node]){
                if(parent[i] == i){
                    parent[i] = findParent(node, parent);
                    q.push(i);
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0;i<edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i<n; i++){
            if(parent[i] == i){
                traverse(i, mp, parent);
            }
        }

        unordered_map<int,int> cnt;
        for(int i = 0;i<n; i++){
            cnt[parent[i]]++;
        }

        long long ans = 0;
        for(auto &i: cnt){
            ans+= (n-i.second)*(long long)(i.second);
            n-=i.second;
        }
        return ans;
    }
};