#define ll long long

class Solution {
public:

    int maximumLength(vector<int>& nums) {
        map<ll,ll> freq;
        for(auto i: nums){
            freq[i]++;
        }
        ll ans = 0;
        for(auto i: freq){
            ll number = i.first;
            ll count = 0;
            while(freq[number] >= 2){
                count+=2;
                freq[number]-=2;
                number*=number;
            }
            if(freq[number]){
                count++;
            }else{
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};