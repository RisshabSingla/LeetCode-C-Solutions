class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;
        for (auto& i : nums) {
            if (i == 1) {
                oneCount++;
            }
        }
        int index1 = 0;
        int index2 = 0;
        int currCount = 0;
        int maxCount = 0;

        while (index2 < 2 * n) {
            if (nums[index2 % n] == 1) {
                currCount++;
            }
            if (index2 - index1 + 1 > oneCount) {
                currCount -= nums[index1 % n];
                index1++;
            }
            maxCount = max(maxCount, currCount);
            index2++;
        }

        return oneCount - maxCount;
    }
};