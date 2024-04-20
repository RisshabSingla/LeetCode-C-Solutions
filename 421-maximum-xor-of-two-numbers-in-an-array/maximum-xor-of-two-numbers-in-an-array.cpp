class TrieNode{
public:
    vector<TrieNode*> children;
    TrieNode(){
        children.resize(2);
        children[0] = children[1] = NULL;
    }
};

class Solution {
public:
    void insertNumber(TrieNode* root, int number){
        TrieNode* parent = root;
        for(int i = 31; i>=0; i--){
            if((number>>i) & 1){
                if(parent->children[1] == NULL){
                    parent->children[1] = new TrieNode();
                }
                parent = parent->children[1];
            }else{
                if(parent->children[0] == NULL){
                    parent->children[0] = new TrieNode();
                }
                parent = parent->children[0];
            }
        }
    }
    int findPossible(TrieNode* root, int number){
        int other = 0;
        TrieNode* parent = root;
        for(int i = 31; i>=0; i--){
            if((number>>i) & 1){
                // want zero
                if(parent->children[0] == NULL){
                    // taking one
                    parent = parent->children[1];
                    other = other | (1<<i);
                }else{
                    // taking zero
                    parent = parent->children[0];
                }
            }else{
                // want one
                if(parent->children[1] == NULL){
                    // taking zero
                    parent = parent->children[0];
                }else{
                    // taking one
                    parent = parent->children[1];
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