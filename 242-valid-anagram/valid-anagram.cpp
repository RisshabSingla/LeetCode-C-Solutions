class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if( slen!= tlen ){
            return false;
        }
        unordered_map<char,int> freq;
        for(int i = 0; i<slen;i++){
            freq[s[i]]++;
        }

        for(int i = 0; i<tlen; i++){
            if(freq.count(t[i]) == 0 || freq[t[i]] == 0){
                return false;
            }else{
                freq[t[i]]--;
            }
        }
        return true;

        
    }
};