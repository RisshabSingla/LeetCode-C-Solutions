class Solution {
public:
    void merge(vector<int>&nums, int start, int mid, int end){
        int size = end-start+1;
        if(size == 1){
            return ;
        }
        vector<int> temp(size);
        int index1 = start;
        int index2 = mid+1;
        int index = 0;
        while(index1<=mid && index2<=end){
            if(nums[index1] >= nums[index2]){
                temp[index] = nums[index2];
                index2++;
            }else{
                temp[index] = nums[index1];
                index1++;
            }
            index++;
        }

        while(index1<=mid){
            temp[index] = nums[index1];
            index1++;
            index++;
        }

         while(index2<=end){
            temp[index] = nums[index2];
            index2++;
            index++;
        }

        for(int i = start; i<=end; i++){
            nums[i] = temp[i-start];
        }
    }

    int countPairs(vector<int>&nums, int start, int mid, int end){
        int count = 0;
        int right = mid+1;
        for(int i = start; i<=mid; i++){
            while(right<=end &&  (long long)(nums[i]) > (long long)(2LL*nums[right])){
                right++;
            }
            count+= (right-(mid+1));
        }
        return count;
    }
    int mergeSort(vector<int>&nums, int start, int end){
        if(start >= end){
            return 0;
        }
        int mid = start + (end-start)/2;
        int a = mergeSort(nums, start, mid);
        int b = mergeSort(nums, mid+1, end);
        int c = countPairs(nums, start, mid, end);
        merge(nums, start, mid, end);
        return (a+b+c);
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};