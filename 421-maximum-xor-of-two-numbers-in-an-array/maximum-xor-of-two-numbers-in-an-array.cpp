class TrieNode{
public:
    TrieNode* zero;
    TrieNode* one;
    TrieNode(){
        zero = NULL;
        one = NULL;
    }
};

class Solution {
public:
    void insertNumber(TrieNode* root, int number){
        TrieNode* parent = root;
        for(int i = 31; i>=0; i--){
            if((number>>i) & 1){
                if(parent->one == NULL){
                    parent->one = new TrieNode();
                }
                parent = parent->one;
            }else{
                if(parent->zero == NULL){
                    parent->zero = new TrieNode();
                }
                parent = parent->zero;
            }
        }
    }
    int findPossible(TrieNode* root, int number){
        int other = 0;
        TrieNode* parent = root;
        for(int i = 31; i>=0; i--){
            if((number>>i) & 1){
                // want zero
                if(parent->zero == NULL){
                    // taking one
                    parent = parent->one;
                    other = other | (1<<i);
                }else{
                    // taking zero
                    parent = parent->zero;
                }
            }else{
                // want one
                if(parent->one == NULL){
                    // taking zero
                    parent = parent->zero;
                }else{
                    // taking one
                    parent = parent->one;
                    other = other | (1<<i);
                }
            }
        }
        return (other xor number);
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int num: nums){
            insertNumber(root, num);
        }
        int maxi = 0;
        for(int num: nums){
            int possible = findPossible(root, num);
            maxi = max(maxi, possible);
        }
        return maxi;
    }
};