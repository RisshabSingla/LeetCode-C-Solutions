class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int val){
        double time = 0.0;
        int size = dist.size();
        for(int i = 0; i<size-1; i++){
            time+= ceil((double)dist[i]/val);
        }
        time+= (double)dist[size-1]/val;
        if(time<=hour){
            return true;
        }
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int size = dist.size();
        int end = 1e7;
        int start = 1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(dist, hour, mid)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};