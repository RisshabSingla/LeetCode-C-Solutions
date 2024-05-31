class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for (auto& num : nums) {
            freq[num]++;
        }
        for (auto& [num, count] : freq) {
            if (count == 1) {
                ans.push_back(num);
                if (ans.size() == 2) {
                    return ans;
                }
            }
        }
        return ans;
    }
};