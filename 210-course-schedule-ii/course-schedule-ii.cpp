class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        map<int, vector<int>> adj_list;
        for(auto &i: prerequisites){
            indegree[i[0]]++;
            adj_list[i[1]].push_back(i[0]);
        }
        vector<int> ans;
        for(int i = 0; i<numCourses; i++){
            int index = -1;
            for(int j = 0; j<numCourses; j++){
                if(indegree[j] == 0){
                    index = j;
                    indegree[j] = -1;
                    break;
                }
            }
            if(index == -1){
                break;
            }
            ans.push_back(index);
            for(auto &i: adj_list[index]){
                indegree[i]--;
            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};