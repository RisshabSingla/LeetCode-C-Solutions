class Solution {
public:
    int helper(vector<int>&cookies, int k , int size, int index, vector<int>&assigned){
        if(index == size){
            int max_value = INT_MIN;
            // cout<<"Assigned is: ";
            for(int i = 0; i<k; i++){
                // cout<<assigned[i]<<" ";
                max_value = max(assigned[i],max_value);
            }
            // cout<<endl;
            return max_value;
        }

        int min_value = INT_MAX;
        for(int j = 0; j<k; j++){
            assigned[j]+=cookies[index];
            int ans = helper(cookies, k,size, index+1, assigned);
            min_value = min(ans, min_value);
            assigned[j]-=cookies[index];
            // backtrack
        }
        return min_value;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int size = cookies.size();
        vector<int> assigned(k,0);
        int ans =  helper(cookies, k, size, 0, assigned);
        return ans;
    }
};