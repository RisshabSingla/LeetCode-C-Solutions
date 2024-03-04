class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        sort(arr.begin(), arr.end());
        int score = 0;
        int front = 0;
        int max_score = 0;
        int end = arr.size()-1;
        while(front<=end){
            if(arr[front] <= power){
                score++;
                power-= arr[front];
                front++;
            }else{
                if(score > 0){
                    score--;
                    power+= arr[end];
                    end--;
                }else{
                    break;
                }
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};