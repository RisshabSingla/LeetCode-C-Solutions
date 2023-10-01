class Solution {
public:
    string reverseWords(string s) {
        int front = 0;
        int last = 0;
        if(s[s.length()-1] != ' '){
            s = s+ ' ';
        }

        while(front<s.length()){
            while(s[last] != ' '){
                last++;
            }

            reverse(s.begin() + front, s.begin() + last);
            front = last+1;
            last++;
        }
        return s.substr(0, s.length()-1);
    }
};