class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> freq(26,0);
        int slen = s.length();
        int max_freq = 0;
        
        for(int i = 0; i<slen;i++){
            freq[s[i]-'a']++;
            max_freq = max(max_freq, freq[s[i]-'a']);
        }
        string str = "";
        for(int i=slen-1; i>=0; i--){
            if(freq[s[i]-'a'] == max_freq){
                str = s[i] + str;
                freq[s[i]-'a'] = 0;
            }
        }
        return str;
        
    }
};