typedef long long ll;
class Solution {
public:
    string getBinary(ll number, ll n) {
        string ans = "";
        while (number) {
            if (number % 2) {
                ans += '1';
            } else {
                ans += '0';
            }
            number /= 2;
        }
        while (ans.length() != n) {
            ans += '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    ll getNumber(string& str, ll n){
        ll number = 0;
        for(int i = 0;i<n; i++){
            number*=2;
            if(str[i] == '1'){
                number++;
            }
        }
        return number;
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (ll i = 0; i < (1 << n); i++) {
            string str = getBinary(i, n);
            string binary = "";
            binary += str[0];
            for (int i = 1; i < n; i++) {
                if (str[i] != str[i - 1]) {
                    binary += '1';
                } else {
                    binary += '0';
                }
            }
            ans.push_back(getNumber(binary, n));
        }
        return ans;
    }
};