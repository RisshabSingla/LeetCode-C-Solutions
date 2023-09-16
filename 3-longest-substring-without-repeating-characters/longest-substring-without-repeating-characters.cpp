class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.length();
        if(slen<=1){
            return slen;
        }
        int left = 0;
        int right = 0;
        int max_length = 0;
        set<char> freq;
        // vector<int> freq(26,0);
        while(right<s.length()){
            // while(right<slen && freq[s[right]-'a'] == 0){
            //     freq[s[right]-'a']++;
            //     right++;
            // }

            while(right<slen && freq.count(s[right]) == 0){
                freq.insert(s[right]);
                right++;
            }
            // cout<<"String is: ";
            // for(int i = left; i<=right; i++){
            //     cout<<s[i];
            // }
            // cout<<endl;
            int len = right-left;
            max_length = max(len, max_length);
            if(right == slen){
                break;
            }
            // while(left<right && freq[s[right]-'a'] != 0){
            //     freq[s[left]-'a']--;
            //     left++;
            // }

            while(left<right && freq.count(s[right]) == 1){
                freq.erase(s[left]);
                // freq[s[left]-'a']--;
                left++;
            }
            // cout<<"String is: ";
            // for(int i = left; i<right; i++){
            //     cout<<s[i];
            // }
            // cout<<endl;
            // cout<<"Left: "<<left<<" Right: "<<right<<endl;
        }
        return max_length;
    }
};