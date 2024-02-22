class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vertical(n, 0);
        vector<int> horizontal(n, 0);
        for(auto&i: trust){
            vertical[i[0]-1]++;
            horizontal[i[1]-1]++;
        }
        int index = -1;
        for(int i = 0; i<n; i++){
            if( vertical[i] == 0 && horizontal[i] == n-1){
                index = i+1;
                break;
            }
        }
        return index;
    }
};