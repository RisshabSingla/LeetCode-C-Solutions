class Solution {
public:
    int finalValueAfterOperations(vector<string>& opr) {
        
        int x = 0;
        for(int i = 0; i<opr.size(); i++){
            if(opr[i][0] == '-' || opr[i][2] == '-'){
                x--;
            }else{
                x++;
            }
        }
        return x;
    }
};