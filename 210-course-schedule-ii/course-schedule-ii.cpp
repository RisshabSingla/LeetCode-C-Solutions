class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj_list;
        for(auto &i: prerequisites){
            indegree[i[0]]++;
            adj_list[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        // for(int i = 0; i<numCourses; i++){
        //     int index = -1;
        //     for(int j = 0; j<numCourses; j++){
        //         if(indegree[j] == 0){
        //             index = j;
        //             indegree[j] = -1;
        //             break;
        //         }
        //     }
        //     if(index == -1){
        //         break;
        //     }
        //     ans.push_back(index);
        //     for(auto &i: adj_list[index]){
        //         indegree[i]--;
        //     }
        // }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto &i: adj_list[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};