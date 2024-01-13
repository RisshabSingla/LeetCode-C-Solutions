class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(int i = 0; i<s.length(); i++){
            freq[s[i]-'a']++;
        }
        int count = 0;
        for(int i = 0; i<t.length(); i++){
            if(freq[t[i] -'a']){
                freq[t[i]-'a']--;
            }else{
                count++;
            }
        }
        return count;
    }
};