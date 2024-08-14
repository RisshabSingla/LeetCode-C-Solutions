class Solution {
public:
    int countPairsWithinDistance(vector<int>& numbers, int targetDistance,
                                 int n) {
        int count = 0;
        int left = 0;
        for (int right = 1; right < n; right++) {
            while (numbers[right] - numbers[left] > targetDistance) {
                left++;
            }
            count += right - left;
        }
        return count;
    }
    int smallestDistancePair(std::vector<int>& numbers, int k) {
        int n = numbers.size();
        sort(numbers.begin(), numbers.end());
        int left = 0;
        int right = numbers[n - 1] - numbers[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countPairsWithinDistance(numbers, mid, n) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
