class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int Find(int node) {
        return parent[node] =
                   (parent[node] == node ? node : Find(parent[node]));
    }

    void Reset(int node) { parent[node] = node; }

    void Union(int one, int two) {
        int oneParent = Find(one);
        int twoParent = Find(two);
        if (oneParent != twoParent) {
            rank[oneParent] < rank[twoParent] ? parent[oneParent] = twoParent
                                                : parent[twoParent] = oneParent;
            rank[oneParent] += (rank[oneParent] == rank[twoParent] ? 1 : 0);
        }
    }
};

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[2] == b[2]){
            return a[0] < b[0];
        }
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,int firstPerson) {
        sort(meetings.begin(),  meetings.end(), comp);
        DSU dsu(n);
        int m = meetings.size();
        dsu.Union(0, firstPerson);
        for(int i = 0; i<m; i++){
            int currTime = meetings[i][2];
            vector<int> currPeople;
            int index = i;
            while(index < m && meetings[index][2] == currTime){
                dsu.Union(meetings[index][0], meetings[index][1]);
                currPeople.push_back(meetings[index][0]);
                currPeople.push_back(meetings[index][1]);
                index++;
            }
            i = max(i, index-1);

            for(auto &people: currPeople){
                if(dsu.Find(people) != dsu.Find(0)){
                    dsu.Reset(people);
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(dsu.Find(i) == dsu.Find(0)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};