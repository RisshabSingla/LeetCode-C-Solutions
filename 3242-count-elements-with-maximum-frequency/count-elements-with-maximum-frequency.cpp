class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int max_freq = -1;
        for(auto i:nums){
            freq[i]++;
            max_freq = max(max_freq, freq[i]);
        }
        int count = 0;
        for(auto i: freq){
            if(i.second == max_freq){
                count += max_freq;
            }
        }
        return count;
    }
};