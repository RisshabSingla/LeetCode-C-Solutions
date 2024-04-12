class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int min_length = min({s1.length(), s2.length(), s3.length()});
        if(s1[0] != s2[0] || s1[0] != s3[0] || s2[0] != s3[0]){
            return -1;
        }
        int count = 0;
        count+= (s1.length()-min_length);
        count+= (s2.length()-min_length);
        count+= (s3.length()-min_length);
        int index = 0;
        for(index = 0; index<=min_length; index++){
            if(s1[index] != s2[index] || s1[index] != s3[index] || s2[index] != s3[index]){
                break;
            }
        }
        if(index == min_length +1){
            return count;
        }
        if(index == 0){
            return -1;
        }
        count+= (3*(min_length - index));
        return count;
    }
};