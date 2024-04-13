class TrieNode{
public:
    int val;
    unordered_map<int, TrieNode*> children;
    TrieNode(){
        val = -1;
    }

    TrieNode(int v){
        val = v;
    }
};


class Solution {
public:
    // int longestPrefix(string& num1 , string& num2){
    //     int n = num1.length();
    //     int m = num2.length();
    //     int i =0 ;
    //     for( i = 0; i<min(n,m); i++){
    //         if(num1[i] != num2[i]){
    //             return i;
    //         }
    //     }
    //     return i;
    // }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        // Approach 1: Using Brute Force
        // int n = arr1.size();
        // int m = arr2.size();
        // int maxi = 0;
        // sort(arr1.begin(), arr1.end(), greater());
        // sort(arr2.begin(), arr2.end(), greater());
        // for(auto &i: arr1){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for(auto &i: arr2){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // vector<string> ar1;
        // vector<string> ar2;
        // unordered_map<int,int> freq1;
        // for(int i = 0; i<n; i++){
        //     if(!freq1.count(arr1[i])){
        //         ar1.push_back(to_string(arr1[i]));
        //         // ar1[i] = to_string();
        //         freq1[arr1[i]]++;
        //     }
        // }
        // freq1.clear();
        
        // for(int i = 0; i<m; i++){
        //     if(!freq1.count(arr2[i])){
        //         ar2.push_back(to_string(arr2[i]));
        //         // ar1[i] = to_string();
        //         freq1[arr2[i]]++;
        //     }
        // }
        // for(int i = 0; i<ar1.size(); i++){
        //     if(ar1[i].length() < maxi){
        //         break;
        //     }
        //     for(int j = 0; j<ar2.size(); j++){
        //         if(ar2[j].length() < maxi){
        //             break;
        //         }
        //         // cout<<"Checking for "<<i<<" "<<j<<"\n";
        //         int a =  longestPrefix(ar1[i], ar2[j]);
        //         // cout<<a<<" ";           
        //         maxi = max(maxi,a);
        //     }
        // }
        // // cout<<"Retuning: "<<maxi<<"\n";
        // return maxi;

        // Approach 2: Using trie

        TrieNode* root = new TrieNode();
        for(int num: arr1){
            string str = to_string(num);
            TrieNode* parent = root;
            for(int i = 0; i<str.length(); i++){
                if(parent->children.count(str[i] - '0')){
                    parent = parent->children[str[i]-'0'];
                }else{
                    TrieNode* newNode = new TrieNode(str[i] - '0');
                    parent->children[str[i]-'0'] = newNode;
                    parent = newNode;
                }
            }
        }

        int maxi = 0;
        for(int num: arr2){
            string str = to_string(num);
            TrieNode* parent = root;
            int index = 0;
            while(parent->children.count(str[index]-'0')){
                parent = parent->children[str[index]-'0'];
                index++;
            }
            maxi = max(maxi , index);
        }
        return maxi;
    }
    
};