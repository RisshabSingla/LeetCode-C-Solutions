class Solution {
public:
    int countKeyChanges(string s) {
        int last = tolower(s[0]);
        int count = 0;
        for(int i = 1; i<s.length(); i++){
            if(tolower(s[i]) != last){
                last = tolower(s[i]);
                count++;
            }
        }
        return count;
    }
};