class Solution {
public:
    bool helper(vector<int>& arr, int i, int j){
         for(int k = j; k>i; k--){
            if(__builtin_popcount(arr[k-1]) != __builtin_popcount(arr[k])){
                return false;
            }else{
                swap(arr[k-1], arr[k]);
            }
        }
        return true;
    }
    bool canSortArray(vector<int>& arr) {
        bool canSort = true;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; canSort &&  j<n; j++){
                if(arr[i] > arr[j]){
                   if(!helper(arr, i,j)){
                       return false;
                   }
                }
            }
        }
        return canSort;
    }
};