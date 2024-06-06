class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        for(int i: hand){
            freq[i]++;
        }

        for(auto &i: freq){
            if(i.second == 0){
                continue;
            }
            int count = i.second;
            for(int j = 0; j<groupSize ; j++){
                if(!freq.count(i.first+j) || freq[i.first+j] < count){
                    return false;
                }
                freq[i.first+j]-= count;
            }
        }
        return true;
    }
};