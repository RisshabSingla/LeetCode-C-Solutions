class Solution {
public:
    // bool checkSame(string str1, string str2, int slen1){
    //     // cout<<"Matching "<<str1<<" and "<<str2<<endl;
    //     // int slen1 = str1.length();
    //     // int slen2 = str2.length();
    //     // if(slen1 != slen2){
    //     //     return false;
    //     // }
    //     unordered_map<char,int> freq;
    //     for(int i = 0;i<slen1; i++){
    //         freq[str1[i]]++;
    //     }
    //     for(int i = 0; i<slen1; i++){
    //         if(freq.count(str2[i]) == 0){
    //             return false;
    //         }else{
    //             if(freq[str2[i]] > 0){
    //                 freq[str2[i]]--;
    //             }else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    string sortedString(string& str){
        vector<int> arr(26,0);
        int slen = str.length();
        for(int i = 0; i<slen; i++){
            arr[str[i]-'a']++;
        }
        string sorted = "";
        for(int i = 0; i<26; i++){
            int count = arr[i];
            while(count>0){
                char ch = 'a' + i;
                sorted = sorted + ch;
                count--;
            }
        }

        return sorted;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapping;

        for(int i = 0; i<strs.size(); i++){
            string sorted = sortedString(strs[i]);
            // cout<<"String is: "<<strs[i]<<endl;
            // cout<<"Sorted is: "<<sorted<<endl;
            mapping[sorted].push_back(strs[i]);
        }

        for(auto i: mapping){
            // vector<string> anagrams = i.second;
            ans.push_back(i.second);
        }
        return ans;        
        
        
        
        // vector<vector<string>> ans;
        // int size = strs.size();
        // if(size == 1){
        //     ans.push_back(vector<string>(1,strs[0]));
        //     return ans;
        // }
        // vector<bool> included(size, false);

        // map<string,int> count;
        // for(int i= 0; i<size; i++){
        //     count[strs[i]]++;
        // }


        // for(int i = 0; i<size;i++){
        //     vector<string> anagram;
        //     anagram.push_back(strs[i]);
        //     int slen1 = strs[i].length();
        //     for(int j = i+1; j<size; j++){
        //         if(slen1 != strs[j].length()){
        //             continue;
        //         }
        //         if(!included[j] &&  
        //             checkSame(strs[i], strs[j], slen1)){
        //             // cout<<"Pushing"<<endl;
        //             included[i] = true;
        //             included[j] = true;
        //             count[strs[i]]--;
        //             count[strs[j]]--;
        //             anagram.push_back(strs[j]);
        //         }
        //     }
        //     if(anagram.size() >1){
        //         ans.push_back(anagram);
        //         included[i] = true;
        //     }
        // }

        // for(auto i: count){
        //     vector<string> anagram;
        //     while(i.second>0){
        //         anagram.push_back(i.first);
        //         i.second--;
        //     }
        //     if(anagram.size() > 0){
        //         ans.push_back(anagram);
        //     }
        // }
        

        // for(int i = 0; i<size; i++){
        //     vector<string> anagram;
        //     if(included.count(strs[i]) == 0){
        //         anagram.push_back(strs[i]);
        //         ans.push_back(anagram);
        //     }else{
        //         included[strs[i]]--;
        //     }
        // }

        // for(auto i : included){
        //     vector<string> anagram;
        //     while(i.second != 0){
        //         anagram.push_back(i.first);
        //         i.second++;
        //     }
        //     if(anagram.size() != 0){
        //         ans.push_back(anagram);
        //     }
        // }

        // return ans;
    }
    



};