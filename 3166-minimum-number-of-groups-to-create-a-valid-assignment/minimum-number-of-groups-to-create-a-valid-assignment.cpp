class Solution {
public:
    int findAns( unordered_map<int,int> &mp, int mini){
        int count = 0;
        for(auto &i: mp){
            int num = i.second/(mini+1);
            int rem = i.second %(mini+1);
            if(rem == 0){
                count+= num;
            }else if(num >= mini-rem){
                count+= (num+1);
            }else{
                return -1;
            }
        }
        return count;
    }
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int,int> mp;
        for(auto i: balls){
            mp[i]++;
        }
        int mini = INT_MAX;
        for(auto &i: mp){
            mini = min(mini, i.second);
            // cout<<i.first<<" : "<<i.second<<"\n";
        }
        int ans = INT_MAX;
        for(int i = 1; i<=mini; i++){
            int count = findAns(mp, i);
            if(count != -1){
                ans = min(ans, count);
            }
        }
        return ans;
    }
};