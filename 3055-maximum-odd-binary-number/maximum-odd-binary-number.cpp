class Solution {
public:
    string maximumOddBinaryNumber(string &str) {
        int ones = 0;
        int zeros = 0;
        int slen = str.length();
        for(int i = 0; i<slen; i++){
            if(str[i] == '1'){
                ones++;
            }else{
                zeros++;
            }
        }
        if(ones == 0){
            return str;
        }
        str[slen-1] = '1';
        ones--;
        for(int i = 0; i<ones; i++){
            str[i] = '1';
        }
        for(int i = ones; i<slen-1; i++){
            str[i] = '0';
        }
        return str;
    }
};