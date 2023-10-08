class Solution {
public:
    bool checkValid(vector<int> &a, vector<int> &b){
        for(int i = 0; i<26; i++){
            if(a[i]!= b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int plen = p.length();
        int slen = s.length();
        vector<int> ans;
        if(plen>slen){
            return ans;
        }
        vector<int> freq(26,0);
        vector<int> pfreq(26,0);
        for(int i = 0; i<plen; i++){
            pfreq[p[i]-'a']++;
        }
        for(int i = 0; i<plen; i++){
            freq[s[i]-'a']++;
        }
        for(int i = plen; i<slen; i++){
            if(checkValid(freq, pfreq)){
                ans.push_back(i-plen);
            }
            freq[s[i-plen]-'a']--;
            freq[s[i]-'a']++;
        }
        if(checkValid(freq, pfreq)){
            ans.push_back(slen-plen);
        }

        return ans;
    }
};