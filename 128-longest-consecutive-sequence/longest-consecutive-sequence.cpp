class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> numbers;
        for(auto &i: nums){
            numbers[i] = false;
        }
        int max_len = 0;
        for(auto &i: numbers){
            if(i.second){
                continue;
            }
            int len = 0;
            int num = i.first;
            while(numbers.count(num)){
                numbers[num] = true;
                num++;
            }
            max_len = max(max_len, num-i.first);
        }
        return max_len;
        // set<int> numbers;
        // for(int i = 0; i<nums.size(); i++){
        //     numbers.insert(nums[i]);
        // }

        // int max_length = 0;
        // int prev = *numbers.begin();
        // int length = 0;
        // // cout<<"Prev is: "<<prev<<endl;
        // for(auto i: numbers){
        //     if(i == prev || i == prev+1){
        //         // cout<<"Number is: "<<i<<endl;
        //         // cout<<"Adding"<<endl;
        //         length++;
        //     }else{
        //         // cout<<"Number is: "<<i<<endl;
        //         // cout<<"broken"<<endl;
        //         max_length = max(length, max_length);
        //         length = 1;
        //     }
        //     prev = i;
        // }
        // max_length = max(length, max_length);
        // return max_length;

    }
};