class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() {
        key = -1;
        value = -1;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insertNode(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        next->prev = node;
        node->next = next;
    }

    void printList() {
        Node* ptr = head;
        while (ptr) {
            cout << ptr->key << " " << ptr->value << "\n";
            ptr = ptr->next;
        }
        cout << "\n";
    }

public:
    Node* head;
    Node* tail;
    int capacity;
    int current;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
        current = 0;
    }

    int get(int key) {
        if (mp.count(key)) {
            deleteNode(mp[key]);
            insertNode(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            deleteNode(mp[key]);
            mp[key]->value = value;
            insertNode(mp[key]);
            return;
        }
        if (current == capacity) {
            Node* lastNode = tail->prev;
            deleteNode(lastNode);
            mp.erase(lastNode->key);
            current--;
        }

        Node* node = new Node();
        node->key = key;
        node->value = value;
        insertNode(node);
        mp[key] = node;
        current++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */