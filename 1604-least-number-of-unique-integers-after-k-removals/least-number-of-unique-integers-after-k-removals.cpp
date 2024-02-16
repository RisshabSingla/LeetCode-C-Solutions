class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        int m = freq.size();
        vector<int> unique(m,0);
        int index = 0;
        for(auto&i : freq){
            unique[index] = i.second;
            index++;
        }
        sort(unique.begin(), unique.end());
        int removed = 0;
        for(int i = 0; i<m; i++){
            if(unique[i] <=k){
                removed++;
                k-=unique[i];
            }else{
                break;
            }
        }
        return m-removed;
    }
};