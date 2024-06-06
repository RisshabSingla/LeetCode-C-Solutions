class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i: nums){
            freq[i]++;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        for(auto &i: freq){
            cout<<i.first<<" "<<i.second<<"\n";
        }
        for(int i = mini; i<=maxi; i++){
            if(!freq.count(i) || freq[i] == 0){
                continue;
            }
            // cout<<"seq: ";
            int count = freq[i];
            for(int j = 0; j<k ; j++){
                if(!freq.count(i+j) || freq[i+j] < count){
                    // cout<<"\ni is: "<<i<<" j: "<<j<<"\n";
                    return false;
                }
                freq[i+j]-= count;
                // cout<<i+j<<" ";
            }
            // cout<<"\n";
            // for(auto &i: freq){
            //     cout<<i.first<<" "<<i.second<<"\n";
            // }
        }
        return true;
    }
};