class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // Approach 1: Using unordered_maps
        // unordered_map<int,int> freq;
        // int mini = INT_MAX;
        // int maxi = INT_MIN;
        // for(int i: nums){
        //     freq[i]++;
        //     mini = min(mini, i);
        //     maxi = max(maxi, i);
        // }
        // for(auto &i: freq){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        // for(int i = mini; i<=maxi; i++){
        //     if(!freq.count(i) || freq[i] == 0){
        //         continue;
        //     }
        //     int count = freq[i];
        //     for(int j = 0; j<k ; j++){
        //         if(!freq.count(i+j) || freq[i+j] < count){
        //             return false;
        //         }
        //         freq[i+j]-= count;
        //     }
        // }
        // return true;


        // Approach 2: Using ordered_maps

        map<int,int> freq;
        for(int i: nums){
            freq[i]++;
        }
        // for(auto &i: freq){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }

        for(auto &i: freq){
            if(i.second == 0){
                continue;
            }
            int count = i.second;
            for(int j = 0; j<k ; j++){
                if(!freq.count(i.first+j) || freq[i.first+j] < count){
                    return false;
                }
                freq[i.first+j]-= count;
            }
        }
        return true;
    }
};