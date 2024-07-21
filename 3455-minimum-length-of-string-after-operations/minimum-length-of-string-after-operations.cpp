class Solution {
public:
    int minimumLength(string &str) {
        unordered_map<char, int> mp;
        for(int i =0; i<str.length(); i++){
            mp[str[i]]++;
        }
        int count = 0;
        for(auto i: mp){
            if(i.second % 2){
                count++;
            }else{
                count+=2;
            }
        }
        return count;
    }
};