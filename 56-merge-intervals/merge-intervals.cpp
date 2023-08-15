class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // cout<<"Intervals is: "<<endl;
        //     for(auto j: intervals){
        //         for(auto k: j){
        //             cout<<k<<" ";
        //         }
        //         cout<<"   ";
        //     }
        //     cout<<endl;

        while(true){
            int count = 0;
            int size = intervals.size();
            vector<int> indexes;
            for(int i = 1; i<size; i++){
                if(intervals[i][0] == -1){
                    continue;
                }
                if(intervals[i][0] <= intervals[i-1][1]){
                    // merge intervals
                    intervals[i-1][1] = max(intervals[i][1], intervals[i-1][1]);
                    count++;
                    intervals[i][0] = -1;
                    intervals[i][1] = -1;
                    indexes.push_back(i);
                }
            // cout<<"indexes is: ";
            // for(auto k: indexes){
            //     cout<<k<<" ";
            // }
            
            // cout<<endl;
            //     cout<<"Intervals Inside is: "<<endl;
            // for(auto j: intervals){
            //     for(auto k: j){
            //         cout<<k<<" ";
            //     }
            //     cout<<"   ";
            // }
            // cout<<endl;
            }
            
            for(int k = indexes.size()-1; k>=0; k--){
                intervals.erase(intervals.begin() + indexes[k]);
            }
            // cout<<"Intervals is: "<<endl;
            // for(auto j: intervals){
            //     for(auto k: j){
            //         cout<<k<<" ";
            //     }
            //     cout<<"   ";
            // }
            // cout<<endl;
            if(count == 0){
                break;
            }
        }
        return intervals;

        // for(auto i: itervals){
        // }

    }
};