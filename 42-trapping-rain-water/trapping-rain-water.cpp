class Solution {
public:
    int trap(vector<int>& height) {
        
        // Approach 1: Brute Force -> O(n^2)

        // int size = height.size();
        // int ans = 0;
        // for(int i = 0; i<size; i++){
        //     int left_max_height = -1;
        //     for(int j = i-1; j>=0; j--){
        //         left_max_height = max(height[j], left_max_height);
        //     }
        //     int right_max_height = -1;
        //     for(int j = i+1; j<size; j++){
        //         right_max_height = max(height[j], right_max_height);
        //     }
        //     // cout<<"For i: "<<i<<" left max is: "<<left_max_height<<" right max is: "<<right_max_height<<endl;
        //     if(left_max_height != -1 && right_max_height != -1){
        //         int a = (min(left_max_height, right_max_height) - height[i]);
        //         // cout<<"Adding: "<<a<<endl;
        //         ans+= max(a,0);
        //     }
        // }
        // return ans;



        // Approach 2: Using Prefix Sums for storing max_heights;
        // int size = height.size();
        // vector<int> left(size, 0);
        // vector<int> right(size, 0);
        // left[0] = height[0];
        // right[size-1] = height[size-1];
        // for(int i = 1; i<size; i++){
        //     left[i] = max(left[i-1], height[i]);
        // }

        // for(int i = size-2; i>=0; i--){
        //     right[i] = max(right[i+1], height[i]);
        // }
        // int ans = 0;
        // for(int i = 1; i<size-1; i++){
        //     int a = min(left[i-1], right[i+1]) - height[i];
        //     if(a>0){
        //         ans+= a;
        //     }
        // }
        // return ans;


        // Approach 3:
        int ans = 0;
        int size = height.size();
        int left_max = 0;
        int right_max = 0;
        int left = 0;
        int right = size-1;
        while(left<right){
            if(height[left]<= height[right]){
                if(height[left]>=left_max){
                    left_max = height[left];
                }else{
                    ans+= (left_max - height[left]);
                }
                left++;
            }else{
                if(height[right]>=right_max){
                    right_max = height[right];
                }else{
                    ans+= (right_max - height[right]);
                }
                right--;
            }
        }
        return ans;
    }
};