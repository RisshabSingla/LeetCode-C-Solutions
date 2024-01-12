class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels({'a','e','i','o','u','A','E','I','O','U'});
        int len = s.length();
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i<len/2; i++){
            if(vowels.count(s[i])){
                count1++;
            }
        }
        for(int i = len/2; i<len; i++){
            if(vowels.count(s[i])){
                count2++;
            }
        }
        return count1==count2;

    }
};