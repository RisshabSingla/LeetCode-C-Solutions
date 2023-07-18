// class LRUCache {
// public:
//     class Node{
//         public: 
//             int key;
//             int val;
//             Node* prev;
//             Node* next;

//             Node(int key, int val){
//                 prev = NULL;
//                 next = NULL;
//                 this->key = key;
//                 this->val = val;
//             }
//     };

//     Node* head = new Node(-1, -1);
//     Node* tail = new Node(-1, -1);

//     int cap;
//     unordered_map<int, Node*> m;

//     LRUCache(int capacity) {
//         cap = capacity;
//         head -> next = tail;
//         tail -> prev = head;
//     }

//     void addNode(Node* newnode){
//         Node* temp = head -> next;
//         newnode -> next = temp;
//         newnode -> prev = head;
        
//         head -> next = newnode;
//         temp -> prev = newnode;
//     }

//     void deleteNode(Node* delnode){
//         Node* prevv = delnode -> prev;
//         Node* nextt = delnode -> next;

//         prevv -> next = nextt;
//         nextt -> prev = prevv;
//     }
    
//     int get(int key) {
//         if(m.find(key) != m.end()){
//             Node* resNode = m[key];
//             int ans = resNode -> val;

//             m.erase(key);
//             deleteNode(resNode);
//             addNode(resNode);

//             m[key] = head -> next;
//             return ans;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(m.find(key) != m.end()){
//             Node* curr = m[key];
//             m.erase(key);
//             deleteNode(curr);
//         }

//         if(m.size() == cap){
//             m.erase(tail -> prev -> key);
//             deleteNode(tail -> prev);
//         }

//         addNode(new Node(key, value));
//         m[key] = head -> next;
//     }
// };



class LRUCache {
public:
    int capacity;
    queue<int> used_history;
    unordered_map<int,int> q_counter;
    unordered_map<int,int> dict;

    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key){
        if(dict.count(key)){
            used_history.push(key);
            q_counter[key]++;
            return dict[key];
        }
        return -1;
    }


    void put(int key, int value){
        used_history.push(key);
        q_counter[key]++;
        dict[key] = value;
        if(dict.size() > this->capacity){
            remove_lru();
        }
    }

    void remove_lru(){
        while(!used_history.empty()){
            int curr = used_history.front();
            used_history.pop();
            q_counter[curr]--;
            if(q_counter[curr] == 0){
                dict.erase(curr);
                break;
            }
        }
    }



};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */