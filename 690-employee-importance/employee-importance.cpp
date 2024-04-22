/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(auto &i: employees){
            mp[i->id] = i;
        }
        int imp = 0;
        queue<Employee*> q;
        q.push(mp[id]);
        mp[id] = NULL;
        while(!q.empty()){
            Employee* front = q.front();
            q.pop();
            imp+= front->importance;
            for(auto &i: front->subordinates){
                if(mp[i] != NULL){
                    q.push(mp[i]);
                    mp[i] = NULL;
                }
            }
        }
        return imp;
    }
};