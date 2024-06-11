class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for (int i : arr1) {
            mp[i]++;
        }
        int index = 0;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < mp[arr2[i]]; j++) {
                arr1[index] = arr2[i];
                index++;
            }
            mp[arr2[i]] = 0;
        }
        int index2 = index;
        for(auto i: mp){
            if(i.second != 0){
                for (int j = 0; j < i.second; j++) {
                    arr1[index2] = i.first;
                    index2++;
                }
            }
        }
        sort(arr1.begin() + index, arr1.end());
        return arr1;
    }
};