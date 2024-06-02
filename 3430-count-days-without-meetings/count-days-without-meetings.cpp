class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int index = 0;
        vector<vector<int>> intervals;
        intervals.push_back(meetings[0]);
        for(int i = 1; i<meetings.size(); i++){
            if(intervals[index][1] >= meetings[i][0]){
                intervals[index][1] = max(intervals[index][1], meetings[i][1]);
            }else{
                intervals.push_back(meetings[i]);
                index++;
            }
        }
        // for(auto i: intervals){
        //     cout<<i[0]<<" "<<i[1]<<"\n";
        // }
        int prev = 1;
        int ans = 0;
        for(auto i: intervals){
            ans+= (i[0]-prev);
            prev = i[1]+1;
        }
        if(prev <= days){
            ans+= (days-prev+1);
        }
        return ans;
    }
};