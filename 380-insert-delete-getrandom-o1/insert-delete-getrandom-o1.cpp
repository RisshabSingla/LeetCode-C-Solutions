class RandomizedSet {
public:
    unordered_set<int> elements;
    RandomizedSet() {
        // *elements = new set<int> ();
    }
    
    bool insert(int val) {
        if(elements.count(val) == 0){
            elements.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        for(auto i: elements){
            if(i == val){
                elements.erase(val);
                return true;
            }
        }
        return false;
    }
    
    int getRandom() {
        int index = rand()%(elements.size());
        int count= 0;
        auto elem = elements.begin();
        for(int i = 0; i<index; i++){
            elem++;
        }
        return *elem;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */