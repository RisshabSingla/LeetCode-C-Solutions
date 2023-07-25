class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size();
        int mid;
        while(start<end){
            mid = start + (end-start)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]){
                start = mid+1;
            }else if(arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]){
                end = mid;
            }
        }
        return mid;
    }
};