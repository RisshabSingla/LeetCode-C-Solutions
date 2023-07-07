class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int size = answerKey.length();
        int countT = 0; // changes from F to T
        int countF = 0;
        int max_length = INT_MIN;
        int frontT = 0;
        int frontF = 0;
        for(int i = 0; i<size; i++){
            if(answerKey[i] == 'F'){
                countT++; 
            }
            if(answerKey[i] == 'T'){
                countF++;
            }
            while(countF>k){
                if(answerKey[frontF] == 'T'){
                    countF--;
                }
                frontF++;
            }
            while(countT>k){
                if(answerKey[frontT] == 'F'){
                    countT--;
                }
                frontT++;
            }
            // frontT++;
            int lengthT = i-frontT+1;
            // if(max_length < lengthT){
            //     max_length = lengthT;
            //     cout<<"KeyT is: ";
            //     for(int k = 0; k<lengthT; k++){
            //         cout<<answerKey[frontT+k]<<" ";
            //     }
            //     cout<<endl;
            // }



            int lengthF = i-frontF+1;
            // if(max_length < lengthF){
            //     max_length = lengthF;
            //     cout<<"KeyF is: ";
            //     for(int k = 0; k<lengthF; k++){
            //         cout<<answerKey[frontF+k]<<" ";
            //     }
            //     cout<<endl;
            // }
            
            max_length = max({max_length, lengthT, lengthF});

            // max_length = max(max_length, length);
        }
        return max_length;



    }
};