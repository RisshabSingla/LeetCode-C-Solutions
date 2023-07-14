class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        
        // Approach 1: Using 2 for loops

        // int longest = 0;
        // int size = arr.size();
        // for(int i = 0; i<size; i++){
        //     int prev = arr[i];
        //     int length = 1;
        //     for(int j = i+1; j<size; j++){
        //         int req = prev + diff;
        //         if(arr[j] == req){
        //             length++;
        //             prev = req;
        //         }
        //     }
        //     longest = max(longest, length);
        // }
        // return longest;

        // Approach 2: Using hash_maps

        // unordered_map<int,vector<int> > mapping;
        // int size = arr.size();
        // for(int i = 0; i<size;i++){
        //     mapping[arr[i]].push_back(i);
        // }
        // int longest = 0;
        // for(int i = 0; i<size; i++){
        //     int curr = arr[i];
        //     int req = curr+ diff;
        //     int last_index = i;
        //     int length = 1;
        //     while(mapping.count(req) > 0){
        //         bool found = false;
        //         for(auto j: mapping[req]){
        //             if(j>last_index){
        //                 length++;
        //                 last_index = j;
        //                 curr = req;
        //                 found = true;
        //                 break;
        //             }
        //         }
        //         if(!found){
        //             break;
        //         }
        //         req = curr+ diff;
        //     }
        //     longest = max(longest, length);
        // }
        // return longest;


        // Approach 3: Using hash_maps

        unordered_map<int,int> mapping;
        int size = arr.size();
        int ans = 1;
        for(int i = 0; i<size; i++){
            int prev = arr[i] - diff;
            if(mapping.count(prev)){
                mapping[arr[i]] = mapping[prev]+1;
            }else{
                mapping[arr[i]] = 1;
            }
            ans = max(ans, mapping[arr[i]]);
        }
        return ans;


    }
};