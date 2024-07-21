class Solution {
public:
    int calculateSteps(vector<int>& nums, int k, int reqDiff, int n) {
        int ans = 0;
        int front = 0;
        int end = n - 1;
        while (front < end) {
            int diff = abs(nums[front] - nums[end]);
            if (diff != reqDiff) {
                int first = nums[front] + reqDiff;
                int second = nums[end] + reqDiff;
                int third = nums[front] - reqDiff;
                int fourth = nums[end] - reqDiff;
                if (first <= k || second <= k) {
                    ans++;
                } else if ((third >= 0 && third <= k) ||
                           (fourth >= 0 && fourth <= k)) {
                    ans++;
                } else {
                    // cout << "Adding 2 front: " << front << " end: " << end <<
                    // "\n";
                    ans += 2;
                }
            }
            front++;
            end--;
        }
        return ans;
    }
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> diffCount;
        vector<int> opr(k+1, 0);

        int front = 0;
        int end = n - 1;
        while(front < end){
            int diff = abs(nums[front] - nums[end]);
            diffCount[diff]++;
            int minElem = min(nums[front], nums[end]);
            int maxElem = max(nums[front], nums[end]);
            int maxDiffPossible = max(k-minElem, maxElem - 0);
            opr[maxDiffPossible]++;
            front++;
            end--;
        }

        for(int i = k-1; i>=0; i--){
            opr[i]+= opr[i+1];
        }

        int ans= INT_MAX;
        for(auto &i: diffCount){
            int zeroOpr = i.second;
            int oneOpr = opr[i.first]-zeroOpr;
            int twoOpr = n/2 - zeroOpr - oneOpr;
            ans = min(ans, oneOpr + 2*twoOpr);
        }
        return ans;
        
        
        
        
        
        
        
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // int front = 0;
        // int end = n - 1;
        // int count = 0;
        // vector<int> reqDiff;
        // while (front < end) {
        //     int diff = abs(nums[front] - nums[end]);
        //     // mp[diff]++;
        //     // if (mp[diff] > count) {
        //     //     count = mp[diff];
        //     //     reqDiff.clear();
        //     //     reqDiff.push_back(diff);
        //     // } else if (mp[diff] == count) {
        //     //     reqDiff.push_back(diff);
        //     // }
        //     mp[diff]++;
        //     front++;
        //     end--;
        // }
        // int ans = INT_MAX;
        // for (auto &i : mp) {
        //     int a = calculateSteps(nums, k, i.first, n);
        //     ans = min(ans, a);
        // }
        // return ans;
    }
};