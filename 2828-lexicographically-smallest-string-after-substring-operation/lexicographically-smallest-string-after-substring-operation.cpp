class Solution {
public:
    string smallestString(string str) {
        int first = -1;
        int slen = str.length();
        for(int i = 0; i<slen;i++){
            if(str[i] != 'a'){
                first = i;
                break;
            }
        }
        if(first == -1){
            str[slen-1] = char('a'+((str[slen-1]-'a'+25)%26));
            return str;
        }
        for(int i = first; i<slen; i++){
            if(str[i] == 'a'){
                break;
            }
            str[i] = char('a'+((str[i]-'a'+25)%26));
        }
        return str;
    }
};