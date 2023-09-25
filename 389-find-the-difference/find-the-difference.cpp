class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
        }
        for(int i = 0; i<t.length(); i++){
            if(freq.count(t[i]) == 0 || freq[t[i]] == 0){
                return t[i];
            }
            freq[t[i]]--;
        }
        return 'a';
    }
};