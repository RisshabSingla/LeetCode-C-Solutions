class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto i: nums1){
            mp1[i]++;
        }
        for(auto i: nums2){
            mp2[i]++;
        }
        vector<int> ans;
        for(auto i: mp1){
            if(mp2.count(i.first)){
                int k = min(i.second, mp2[i.first]);
                for(int j = 0; j<k; j++){
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};