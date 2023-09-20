class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> mapping;
        int ans = INT_MAX;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            mapping[sum] = (i+1);
            if(sum == x){
                ans = min(ans, i+1);
            }
        }

        sum = 0;
        for(int i = n-1; i>=0 ; i--){
            sum+= nums[i];
            int req = x-sum;
            if(sum == x){
                ans = min(ans, n-i);
            }
            if(mapping.count(req)){
                if(mapping[req] < i){
                    // cout<<"Sum is: "<<sum<<endl;
                    // cout<<"Mapping is: "<<mapping[req]<<endl;
                    // cout<<"Index is: "<<n-i+1<<endl;
                    // cout<<"Ans is: "<<ans<<endl;
                    ans = min(ans, mapping[req]+n-i);
                    // cout<<"Ans is: "<<ans<<endl;
                }
            }
        }

        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};