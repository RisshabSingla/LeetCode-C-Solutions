class Solution {
public:
    // vector<string> letters;
    vector<string> letters = {"","", "abc", "def","ghi","jkl","mno","pqrs", "tuv", "wxyz"};
    vector<string> helper(string digits){
       

        if(digits.length() == 0){
            vector<string> ans;
            ans.push_back("");
            // cout<<"returning empty"<<endl;
            return ans;
        }

        vector<string> ans = helper(digits.substr(1));
        int size = ans.size();
        int number = digits[0] - '0';
        string possible = letters[number];
        int new_size = ans.size() * possible.length();

        vector<string> new_ans(new_size);
        for(int i = 0; i<size; i++){
            new_ans[i] = ans[i];
        }

        for(int i = size; i<new_size; i++){
            new_ans[i] = ans[i%size];
        }

        int index = 0;
        for(int i = 0; i<new_size; i++){
            if(i% size == 0 && i>0){
                index++;
            }
            new_ans[i] = possible[index] +  new_ans[i] ;
        }
        return new_ans;




        // cout<<"got ans with size: "<<ans.size()<<endl;
        // int size = ans.size();
        // int number = digits[0] - '0';
        // cout<<"Number is: "<<number<<endl;
        // string possible = letters[number];
        // cout<<"Possible is: "<<possible<<endl;
        // // int new_size = ans.size() * possible.length();
        
        // // creating the new possible combinations
        // for(int i = 0; i<possible.length(); i++){
        //     for(int j = 0; j<size; j++){
        //         // string str = ans[j] + possible[i];
        //         ans.push_back(ans[j]);
        //     }
        // }
        // cout<<"New ans is: ";
        // for(int i = 0; i<ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        // int index = 0;
        // for(int i = 0; i<possible.length(); i++){
        //     for(int j = index; j<= index*size; j++){
        //         ans[j] = possible[i] + ans[j];
        //         // cout<<"";
        //     }
        //     index+=size;
        // }

        // cout<<"New ans after changing is: ";
        // for(int i = 0; i<ans.size(); i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;
        // return ans;
    }

    vector<string> letterCombinations(string digits) {
       
        
        if(digits.length() == 0){
            vector<string> a;
            return a;
        }

        vector<string> ans = helper(digits);
        return ans;

        // vector<string> ans;
        // ans.push_back("");
        // for(int i = 0; i<digits.length(); i++){
        //     char digit = digits[i];
        //     string possible = letters[digit];
        //     int size = ans.size();
        //     int new_size = possible.length() * size;
        //     for(int i = size; i<new_size; i++){
        //         ans.push_back(ans[i-1]);
        //     }
        //     for(int i = 0; i<possible.length(); i++){

        //         for(int )
        //     }
        // }


        // return letters;
    }
};