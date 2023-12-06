class Solution {
public:
    int totalMoney(int n) {
        int start = 0;
        int total = 0;
        int add = 1;
        for(int i = 0; i<n; i++){
            if(i%7 == 0){
                start++;
                add = start;
            }
            total+= add;
            add++;
        }
        return total;
    }
};