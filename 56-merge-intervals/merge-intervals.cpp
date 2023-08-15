class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        // Approach 1: Checking all the intervals and comparing
        // -> O(n^2) 
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> ans;

        // while(true){
        //     int count = 0;
        //     int size = intervals.size();
        //     vector<int> indexes;
        //     for(int i = 1; i<size; i++){
        //         if(intervals[i][0] == -1){
        //             continue;
        //         }
        //         if(intervals[i][0] <= intervals[i-1][1]){
        //             // merge intervals
        //             intervals[i-1][1] = max(intervals[i][1], intervals[i-1][1]);
        //             count++;
        //             intervals[i][0] = -1;
        //             intervals[i][1] = -1;
        //             indexes.push_back(i);
        //         }
        //     }
            
        //     for(int k = indexes.size()-1; k>=0; k--){
        //         intervals.erase(intervals.begin() + indexes[k]);
        //     }
        //     if(count == 0){
        //         break;
        //     }
        // }
        // return intervals;



        // Approach 2: O(n) -> Checking according to the final intervals

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        // int start = intervals[0][0];
        int end = intervals[0][1];
        int index = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                // merging the intervals
                ans[index][1] = max(ans[index][1], intervals[i][1]);
                end = ans[index][1];
            }else{
                ans.push_back(intervals[i]);
                end = intervals[i][1];
                index++;
            }
        }
        return ans;







    }
};