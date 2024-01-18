class Solution {
public:
    // string ans ="";
    // void recursive(string &str, vector<string>& dictionary, string &a, int index){
    //     if(index == str.length()){
    //         cout<<"A is: "<<a<<"\n";
    //         if(find(dictionary.begin(), dictionary.end(), a) != dictionary.end()){
    //             if(ans.length() < a.length()){
    //                 ans = a;
    //             }
    //         }
    //         return;
    //     }
    //     a.push_back(str[index]);
    //     recursive(str, dictionary, a, index+1);
    //     a.pop_back();
    //     recursive(str, dictionary, a, index+1);
    // }

    bool isPresent(string &str, string &word){
        int index = 0;
        for(int i = 0; i<str.length(); i++){
            if(word[index] == str[i]){
                index++;
            }
            if(index == word.length()){
                return true;
            }
        }
        if(index == word.length()){
            return true;
        }
        return false;
    }
    static bool comp(string& a, string&b){
        if(a.length() == b.length()){
            return a<b;
        }
        return a.length() < b.length();
    }
    string findLongestWord(string &str, vector<string>& dictionary) {
        // string a = "";
        // recursive(str, dictionary,a, 0);
        // return ans;
        sort(dictionary.begin(), dictionary.end(), comp);
        string ans = "";
        for(int i = 0; i<dictionary.size(); i++){
            if(ans.length() == dictionary[i].length()){
                continue;
            }
            // bool present = isPresent(str, dictionary[i]);
            // cout<<"Word: "<<dictionary[i]<<": "<<present<<"\n";
            if(isPresent(str, dictionary[i])){
                ans = dictionary[i];
            }
        }
        return ans;
    }
};