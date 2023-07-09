class Solution {
public:
    int kadane(char c1, char c2, string &str){
        int count1 = 0;
        int count2 = 0;
        int variance = 0;
        int size = str.length();
        for(int i = 0; i<size; i++){
            if(str[i] == c1){
                count1++;
            }
            if(str[i] == c2){
                count2++;
            }
            if(count1<count2){
                count1 = 0;
                count2 = 0;
            }
            if(count1 > 0 && count2>0){
                variance = max(variance, count1-count2);
            }
        }
        if(count1 > 0 && count2>0){
            variance = max(variance, count1-count2);
        }

        return variance;
    }
    int largestVariance(string s) {
        int variance = 0;
        for(char ch1 = 'a'; ch1<='z'; ch1++){
            for(char ch2 = 'a'; ch2 <='z'; ch2++){
                int a = kadane(ch1,ch2, s);
                variance = max(variance, a);
            }
        }
        reverse(s.begin(), s.end());
        for(char ch1 = 'a'; ch1<='z'; ch1++){
            for(char ch2 = 'a'; ch2 <='z'; ch2++){
                int a = kadane(ch1,ch2, s);
                variance = max(variance, a);
            }
        }

        return variance;
    }
};