class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr = 0;
        for(auto &i: logs){
            if(i[0] == '.' && i[1] == '.'){
                curr = max(curr-1, 0);
            }else if(i[0] != '.' ){
                curr++;
            }
        }
        return curr;
    }
};