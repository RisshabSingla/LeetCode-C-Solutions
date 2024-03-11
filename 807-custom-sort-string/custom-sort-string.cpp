class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        s = "";
        for(int i = 0; i<order.length(); i++){
            if(freq[order[i]-'a'] > 0){
                s+= string(freq[order[i]-'a'], order[i]);
                freq[order[i]-'a'] = 0;
            }
        }

        for(int i = 0; i<26; i++){
            if(freq[i] != 0){
                char ch = 'a'+i;
                s+= string(freq[i], ch);
            }
        }
        return s;

    }
};