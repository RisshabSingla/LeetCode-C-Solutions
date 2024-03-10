class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> unique;
        set<int> ans;
        for(int i = 0; i<nums1.size(); i++){
            unique.insert(nums1[i]);
        }

        for(int i = 0; i<nums2.size(); i++){
            auto itr = unique.find(nums2[i]);
            if(itr!= unique.end()){
                ans.insert(nums2[i]);
            }
        }
        vector<int> a;
        for(auto i: ans){
            a.push_back(i);
        }
        return a;
    }
};