class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        // if(a[1] == b[1]){
        //     return a[0] < b[0];
        // }
        return a[1] < b[1];
    } 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if(size == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end(),comp);
        // for(auto i: intervals){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        int count = 0;
        int prev = intervals[0][1];
        for(int i = 1; i<size; i++){
            if(prev > intervals[i][0]){
                count++;
            }else{
                prev = intervals[i][1];
            }
        }

        return count;
    }
};