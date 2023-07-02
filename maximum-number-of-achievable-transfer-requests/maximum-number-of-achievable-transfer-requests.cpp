class Solution {
public:
    int satisfied = 0;
    void helper(vector<vector<int>>& requests, int index, int n, vector<int> &numbers, int req_size, int count){
        if(index == req_size){
            for(int i = 0; i<n; i++){
                if(numbers[i] != 0){
                    return;
                }
            }
            satisfied = max(satisfied, count);
            return;
        }
        int from = requests[index][0];
        int to = requests[index][1];
        numbers[from]--;
        numbers[to]++;
        helper(requests, index+1, n, numbers, req_size, count+1);
        // backtrack -> not fulfilled request
        numbers[from]++;
        numbers[to]--;
        helper(requests, index+1, n, numbers, req_size, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> numbers(n,0);
        int size = requests.size();
        helper(requests, 0,n, numbers, size, 0);
        return satisfied;

    }
};