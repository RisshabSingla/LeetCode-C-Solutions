class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>s(nums.begin(),nums.end());
        vector<int>temp(s.begin(),s.end());

        int ans=1e9;
        for(int i=0;i<temp.size();i++){
            int low=temp[i];
            int high=low+n-1;
             int j=upper_bound(temp.begin(),temp.end(),high)-temp.begin();
             int withinrange=j-i;
             int outofrange=n-withinrange;
            ans=min(ans,outofrange);
       }
       return ans;
    }
};