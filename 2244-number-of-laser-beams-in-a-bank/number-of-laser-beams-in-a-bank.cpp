class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int rows = bank.size();
        vector<int> number(rows, 0);
        for(int i = 0; i<rows; i++){
            int count = 0;
            for(char ch: bank[i]){
                if(ch == '1'){
                    count++;
                }
            }
            number[i] = count;
        }
        int prev = number[0];
        int ans = 0;
        for(int i = 1; i<rows; i++){
            if(number[i] == 0){
                continue;
            }
            ans+= prev*number[i];
            prev = number[i];
        }
        return ans;
    }
};