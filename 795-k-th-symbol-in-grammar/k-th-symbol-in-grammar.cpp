class Solution {
public:
    int recursion(int n, int k, string str){
        if(n == 1){
            return str[k-1] -'0';
        }
        string new_string = "";
        for(int i = 0; i<str.length(); i++){
            if(str[i] == '0'){
                new_string += "01";
            }else{
                new_string+= "10";
            }
        }
        return recursion(n-1, k, new_string);
    }
    int calc(int n, int k){
        if(n == 1){
            return 0;
        }
        int rec = calc(n-1, k/2);
        if(k % 2 == 0){
            if(rec == 0){
                return 0;
            } 
            return 1;
        }
        if(rec == 0){
            return 1;
        }
        return 0;
    }

    int kthGrammar(int n, int k) {
        // return recursion(n,k,"0");
        return calc(n,k-1);
    }
};