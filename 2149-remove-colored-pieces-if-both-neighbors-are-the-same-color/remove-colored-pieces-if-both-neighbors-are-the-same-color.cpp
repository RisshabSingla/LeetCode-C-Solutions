class Solution {
public:
    bool winnerOfGame(string colors) {
        int consB = 0;
        int consA = 0;
        int n = colors.size();
        for(int i = 2; i<n; i++){
            if(colors[i-2] == colors[i-1] && colors[i-1] == colors[i]){
                if(colors[i] == 'A'){
                    consA++;
                }else{
                    consB++;
                }
            }
        }

        if(consA > consB){
            return true;
        }
        return false;


    }
};