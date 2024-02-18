class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {
        vector<int> roomcnt(n, 0);
        set<int> s;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        sort(arr.begin(), arr.end());
        int m = arr.size();
        for (int i = 0; i < n; i++) {
            s.insert(i);
        }
        for (int i = 0; i < m; i++) {
            long long start = arr[i][0];
            long long end = arr[i][1];
            while (q.size() > 0 && q.top().first <= start) {
                int room = q.top().second;
                q.pop();
                s.insert(room);
            }
            if (s.size() == 0) {
                pair<long long, long long> p = q.top();
                q.pop();
                long long dif = end - start;
                start = p.first;
                end = start + dif;
                s.insert(p.second);
            }
            auto it = s.begin();
            roomcnt[*it]++;
            q.push({end, *it});
            s.erase(*it);
        }
        int ans = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (maxi < roomcnt[i]) {
                maxi = roomcnt[i];
                ans = i;
            }
        }
        return ans;
    }
};