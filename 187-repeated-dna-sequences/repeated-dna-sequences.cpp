class Solution {
public:
    vector<string> findRepeatedDnaSequences(string& str) {
        unordered_map<string,int> freq;
        string dna = str.substr(0,10);
        freq[dna] = 1;
        for(int i = 10; i<str.length(); i++){
            dna = dna.erase(0,1);
            dna.push_back(str[i]);
            freq[dna]++;
        }
        vector<string> ans;
        for(auto &itr: freq){
            if(itr.second > 1){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};