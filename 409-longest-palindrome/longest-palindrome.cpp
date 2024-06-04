class Solution {
public:
    int longestPalindrome(string s) {
        int slen = s.length();
        if(slen == 1){
            return slen;
        }

        vector<int>freq(52,0);
        for(int i = 0; i<slen; i++){
            if(isupper(s[i])){
                freq[s[i] - 'A' + 26]++;
            }else{
                freq[s[i] - 'a']++;
            }
        }

        sort(freq.begin(), freq.end(), greater());
        bool oddtaken = false;
        int count = 0;
        for(int i = 0; i<52; i++){
            int c = freq[i];
            if(c%2 == 0){
                count+=c;
            }else{
                if(!oddtaken){
                    count+=c;
                    oddtaken = true;
                }else{
                    count+=(c-1);
                }
            }
        }
        return count;
    }
};