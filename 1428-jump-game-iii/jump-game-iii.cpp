class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int size = arr.size();
        vector<bool> visited(size, false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(visited[index]){
                continue;
            }
            if(arr[index] == 0){
                return true;
            }
            int val = arr[index];
            visited[index] = true;
            if(index + val <size){
                q.push(index+val);
            }
            if(index-val >=0){
                q.push(index-val);
            }
        }
        return false;

    }
};