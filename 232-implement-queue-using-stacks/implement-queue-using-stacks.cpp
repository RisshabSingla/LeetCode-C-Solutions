class MyQueue {
public:
    stack<int> queue;
    stack<int> buffer;
    MyQueue() {
        
    }
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        while(queue.size()!= 1){
            buffer.push(queue.top());
            queue.pop();
        }
        int elem = queue.top();
        queue.pop();
        while(buffer.size() != 0){
            queue.push(buffer.top());
            buffer.pop();
        }
        return elem;
    }
    
    int peek() {
        while(queue.size()!= 1){
            buffer.push(queue.top());
            queue.pop();
        }
        int elem = queue.top();
        queue.pop();
        buffer.push(elem);
        while(buffer.size() != 0){
            queue.push(buffer.top());
            buffer.pop();
        }
        return elem;
    }
    
    bool empty() {
        return !(queue.size()>0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */