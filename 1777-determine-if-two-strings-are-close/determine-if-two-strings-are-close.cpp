class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<int> present1(26,false);
        vector<int> present2(26,false);
        for(int i = 0; i<word1.length(); i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
            present1[word1[i]-'a'] = true;
            present2[word2[i]-'a'] = true;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2 && present1==present2;
    }
};