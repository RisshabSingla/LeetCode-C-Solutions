class Solution {
public: 
    static bool comp(pair<int,int>&a, pair<int,int> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        vector<pair<int,int>> arr;
        for(auto i: mp){
            arr.push_back({i.second, i.first});
        }
        sort(arr.begin(), arr.end(), comp);
        int index = 0;
        for(auto i: arr){
            while(i.first--){
                nums[index] = i.second;
                index++;
            }
        }
        return nums;
    }
};