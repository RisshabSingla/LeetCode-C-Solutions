class Solution {
public:
    //  int findCost2(vector<priority_queue<pair<int,int>>> &count, int index, int cols,int prev, int n){
    //     if(index == cols){
    //         return 0;
    //     }
    //     int cost = 10000;
    //     for(int i = 0; i<4; i++ ){
    //         pair<int,int> top = count[index].top();
    //         count[index].pop();
    //         if(top.second == prev){
    //             continue;
    //         }
    //         int c = findCost2(count, index+1, cols, top.second,n) + (n - top.first);
    //         // cout<<"i is: "<<i<<" index: "<<index<<" cost: "<<c<<"\n";
    //         cost = min(cost, c);
    //     }
    //     return cost;
    // }
    map<pair<int,int>, int> dp;
    int findCost(vector<unordered_map<int,int>> &count, int index, int cols,int prev, int n){
        if(index == cols){
            return 0;
        }
        int cost = 1000000;
        for(int i = 0; i<10; i++){
            if(i == prev){
                continue;
            }
            int c = 1000000;
            if(dp.count({index, i})){
                c = dp[{index, i}];
            }else{
                c = findCost(count, index+1, cols, i,n) + (n - count[index][i]);
                dp[{index, i}] = c;
            }
            // cout<<"i is: "<<i<<" index: "<<index<<" cost: "<<c<<"\n";
            cost = min(cost, c);
        }
        return cost;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if(n == 1){
        //     int count = 0;
        //     for(int i = 1; i<m; i++){
        //         if(grid[0][i] == grid[0][i-1]){
        //             count++;
        //         }
        //     }
        //     return count;
        // }
        vector<unordered_map<int,int>> cnt(m);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cnt[i][grid[j][i]]++;
            }
        }
        vector<priority_queue<pair<int,int>>> counts(m);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<10; j++){
                if(cnt[i].count(j)){
                    counts[i].push({cnt[i][j], j});
                }
            }
        }
        
        
        
        // for(int j = 0;j<m; j++){
        //     for(auto &i: count[j]){
        //         cout<<i.first<<" "<<i.second<<"\n";
        //     }
        //     cout<<"\n";
        // }
        // return findCost2(counts, 0, m, -1, n);
        return findCost(cnt, 0, m, -1, n);
        
        
        
    }
};