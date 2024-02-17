class Solution {
public:
    bool isPossible[1000005];
    int recursive(map<int,int>&freq, int start){
        int count = 0;
        bool nextPossible = false;
        // if(freq[start] > 1){
        //     nextPossible = true;
        // }
        while(nextPossible || freq.count(start)){
            // if(nextPossible){
            //     nextPossible = false;
            // }
            if(freq.count(start)){
                isPossible[start+1] = true;
                if(freq[start] == 1 && !nextPossible){
                    nextPossible = false;
                }
                if(freq[start] > 1){
                    nextPossible  = true;
                }
                
            }else{
                nextPossible = false;
            }
            freq[start] = 0;
            // freq[start] = max(freq[start], 1);
            start++;
            count++;
        }
        return count;
    }
    int maxSelectedElements(vector<int>& nums) {
        memset(isPossible, false, sizeof(isPossible));
        map<int,int> freq;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        // for(auto &i: freq){
        //     cout<<i.first<<" "<<i.second<<"\n";
        // }
        // cout<<"\n";
        int maxi = 1;
        for(auto &i: freq){
            // cout<<"for: "<<i.first<<" ";
            if(i.second != 0){
                int a = recursive(freq, i.first);
                int index = i.first-1;
                int count = 0;
                while(index>= 0 && isPossible[index]){
                    index--;
                    count++;
                }
                // cout<<a<<" "<<count;
                maxi = max(maxi, a+count);
            }   
            // cout<<"\n";
        }
        return maxi;
    }
};