class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int pivot = -1;
        int size = nums.size();
        for(int i = size-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                pivot = i-1;
                break;
            }
        }
        if(pivot == -1){
            sort(nums.begin(), nums.end());
            return;
        }   
        cout<<"Pivot is: "<<pivot<<endl;
        int min_greater = INT_MAX;
        int index = 0;
        for(int j = pivot; j<size; j++){
            if(nums[j]> nums[pivot]){
                if(nums[j]<min_greater){
                    min_greater = nums[j];
                    index = j;
                }
            }
        }
        cout<<"index is: "<<index<<endl;
        swap(nums[pivot], nums[index]);
        sort(nums.begin()+pivot+1, nums.end());
        for(int i =0; i<size; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};