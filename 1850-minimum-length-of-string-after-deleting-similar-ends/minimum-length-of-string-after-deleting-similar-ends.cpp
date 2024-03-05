class Solution {
public:
    int minimumLength(string &str) {
        int slen = str.length();
        int front = 0;
        int end = slen-1;
        while(front<end){
            if(str[front] != str[end]){
                break;
            }
            char ch = str[front];
            int index = front;
            while(index<end && str[index] == ch){
                index++;
            }
            front = max(front, index-1);
            index = end;
            while(index> front && str[index] == ch){
                index--;
            } 
            end = min(end, index+1);
            front++;
            end--;
        }
        return end-front+1;
    }
};