class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int front = 0;
        int last = s.length()-1;
        int mid = (last+1)/2;
        int count = 0;
        while(front<last){
            if(s[front] == s[last]){
                front++;
                last--;
            }else{
                int i = last-1;
                for(; i>=front; i--){
                    if(s[i] == s[front]){
                        break;
                    }
                }
                if( i == front){
                    swap(s[front], s[front+1]);
                    count++;
                    continue;
                }
                for(int j = i; j<last; j++){
                    swap(s[j], s[j+1]);
                    count++;
                }
                front++;
                last--;
            }
        }
        return count;
    }
};