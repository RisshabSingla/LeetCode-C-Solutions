class Solution {
public:
    string base(int n, int b){
        string str = "";
        while(n>0){
            int l = n%b;
            str = to_string(l) + str;
            n = n/b;
        }
        return str;
    }

    bool checkPalindrome(string str){
        int front = 0;
        int end = str.length()-1;
        while(front<end){
            if(str[front] != str[end]){
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i<=n-2; i++){
            string str = base(n, i);
            if(!checkPalindrome(str)){
                return false;
            }
            // cout<<"base: "<<i<<" str: "<<str<<endl; 
        }
        return true;
    }
};