class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_length = -1;
        unordered_map<char,int> last_occ;
        for(int i = 0; i<s.length(); i++){
            if(last_occ.count(s[i])){
                max_length = max(max_length, i-last_occ[s[i]]-1);
            }else{
                last_occ[s[i]] = i;
            }
        }
        return max_length;
    }
};