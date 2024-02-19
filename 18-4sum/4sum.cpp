class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            for(int j = i+1; j<n-1; j++){
                if(j > i+1 && arr[j] == arr[j-1]){
                    continue;
                }
                int k = j+1;
                int l = n-1;
                while(k < l && k< n){
                    long long sum = arr[i]+arr[j];
                    if(arr[k] > 0){
                        if(target < sum){
                            break;
                        }
                    }
                    sum+= (arr[k] + arr[l]);
                    if(sum == target){
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                        k++;
                        l--;
                        while(k< n && arr[k-1] == arr[k]){
                            k++;
                        }
                        while(l > k && arr[l] == arr[l+1]){
                            l--;
                        }
                    }else{
                        if(sum < target){
                            k++;
                        }else{
                            l--;
                        }
                    }
                }

                // while(j < n && arr[j] == arr[j-1]){
                //     j++;
                // }
                // if(inc){
                //     j--;
                // }
            }

            // while(i < n && arr[i-1] == arr[i]){
            //     i++;
            // }
            // if(inc){
            //     i--;
            // }
            
        }
        return ans;
    }
};