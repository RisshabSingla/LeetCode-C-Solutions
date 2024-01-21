class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto i: word){
            freq[i-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int count = 0;
        int index = 0;
        for(int i = 0; i<26; i++){
            if(freq[i] == 0){
                break;
            }
            if(i%8 == 0){
                index++;
            }
            count+= (index)*freq[i];
        }
        return count;
    }
};