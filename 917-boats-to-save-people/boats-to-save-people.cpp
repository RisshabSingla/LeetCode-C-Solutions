class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int front = 0;
        int n = people.size();
        int end = n-1;
        int req = 0;
        while(front <= end){
            int w = 0;
            int p = 0;
            while(p< 2 && end >= front && w + people[end] <= limit){
                w+= people[end];
                end--;
                p++;
            }

            while(p<2 && front < n && front < end && w + people[front] <= limit){
                w+= people[front];
                front++;
                p++;
            }
            req++;
        }
        return req;
    }
};