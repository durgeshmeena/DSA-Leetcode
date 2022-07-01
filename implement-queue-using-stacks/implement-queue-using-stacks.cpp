class MyQueue {
public:
    
    stack<int> front;
    stack<int> back;
    int sz;
    
    MyQueue() {
        sz=0;
    }
    
    void push(int x) {
        back.push(x);
        sz++;
    }
    
    void insert(){
        for(int i=0; i<sz; i++){
            int val = back.top();
            front.push(val);
            back.pop();
        }   
        back = {};    
    }
    
    int pop() {
        if(!front.size()){
            insert();
        }
        sz--;
        int f = front.top();
        front.pop();
        return f;
        
        
             
    }
    
    int peek() {
        if(!front.size())
            insert();
        return front.top();
    }
    
    bool empty() {
        return sz == 0;
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