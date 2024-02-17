class Solution {
public:
    int furthestBuilding(vector<int>& arr, int bricks, int ladder) {
        priority_queue<int> pq;
        int i = 0, diff = 0;
        for (i = 0; i < arr.size() - 1; i++) {
            diff = arr[i + 1] - arr[i];
            if (diff <= 0) {
                continue;
            }
            bricks -= diff;
            pq.push(diff);
            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladder--;
            }
            if (ladder < 0) {
                break;
            }
        }
        return i;
    }
};
