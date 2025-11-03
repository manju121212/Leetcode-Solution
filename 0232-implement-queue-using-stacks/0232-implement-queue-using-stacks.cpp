class Node{
    public:
    int data;
    Node* next ;

    Node(int data){
        this->data  = data;
        next = NULL;
    }

};

class MyQueue {
public:
    Node* front;
    Node* rear;
    MyQueue() {
        front = NULL;
        rear = NULL;
    }
    
    void push(int x) {
        Node* node = new Node(x);
        if(front == NULL){
            front = node;
            rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
    }
    
    int pop() {
        
        if(front == NULL){
            return -1;
        }
        else{
            Node* store = front;
            int temp = store->data;
            front = front->next;
            delete store;
            return temp;
        }
    }
    
    int peek() {
        if(front == NULL){
              return -1;
        }
        return front->data;
    }
    
    bool empty() {
        if(front == NULL){
             return true;
        }
        return false;
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