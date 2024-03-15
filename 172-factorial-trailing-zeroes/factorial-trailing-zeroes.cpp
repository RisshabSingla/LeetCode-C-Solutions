class Solution {
public:
    int trailingZeroes(int n) {
        int five = 5;
        int count = 0;
        while(n / five > 0){
            count+= n/five;
            five*=5;
        }
        return count;
    }
};