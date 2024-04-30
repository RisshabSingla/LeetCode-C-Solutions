typedef long long ll;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> mp;
        ll prefix = 0;
        mp[0] = 1;
        ll ans = 0;
        for(int i=0;i<word.length(); i++){
            prefix = prefix xor (1<<(word[i]-'a'));
            ans+= mp[prefix]; 
            for(char ch = 'a'; ch<= 'j'; ch++){
                ll oddpattern = prefix xor (1<<(ch-'a'));
                ans+= mp[oddpattern];
            }
            mp[prefix]++;
        }
        return ans;
    }
    
};