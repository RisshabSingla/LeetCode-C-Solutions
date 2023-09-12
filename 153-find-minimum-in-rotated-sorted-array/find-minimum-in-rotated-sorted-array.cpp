class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_element = INT_MAX;
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[left]<=nums[right]){
                // array is completely sorted
                min_element = min(min_element, nums[left]);
                break;
            }
            if(nums[left]<=nums[mid]){
                // left part is sorted
                min_element = min(min_element, nums[left]);
                left = mid+1;
            }else{
                // right part is sorted
                min_element = min(min_element, nums[mid]);
                right = mid-1;
            }
        }
        return min_element;
    }
};