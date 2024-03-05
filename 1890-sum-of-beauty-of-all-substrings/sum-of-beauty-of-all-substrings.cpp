class Solution {
public:
    int calcBeauty(string&str, int start, int end){
        vector<int> freq(26, 0);
        int mini = INT_MAX;
        int maxi = 0;
        for(int i = start; i<=end; i++){
            freq[str[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq[i] == 0){
                continue;
            }
            mini = min(mini, freq[i]);
            maxi = max(maxi, freq[i]);
        }
        return maxi-mini;
    }
    int beautySum(string &s) {
        int sum = 0;
        int slen = s.length();
        for(int i = 0; i<slen; i++){
            for(int j = i+1; j<slen; j++){
                sum+= calcBeauty(s, i,j);
            }
        }
        return sum;
    }
};