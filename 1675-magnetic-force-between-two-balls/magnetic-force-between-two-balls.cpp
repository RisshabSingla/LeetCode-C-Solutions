class Solution {
public:
    bool isPossible(vector<int>& position, int m, int force){
        int point = position[0];
        m--;
        while(m){
            point+= force;
            auto itr = lower_bound(position.begin(), position.end(), point);
            if(itr == position.end()){
                return false;
            }
            point = *itr;
            m--;
        }
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0;
        int high = INT_MAX;
        int ans = 0;
        while(low<= high){
            int mid = low + (high-low)/2;
            if(isPossible(position, m, mid)){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};