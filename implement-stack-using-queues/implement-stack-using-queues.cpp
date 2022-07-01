class MyStack {
public:
    
    queue<int> q;
    int sz, front;
    
    MyStack() {
        sz = 0;
    }
    
    void push(int x) {
        q.push(x);
        sz++;
        front = x;
    }
    
    int pop() {
        sz--;
        for(int i=0; i<sz; i++){
            int val = q.front();
            q.pop();
            q.push(val);
            front = val;
        }
        int p = q.front();
        q.pop();
        return p;
    }
    
    int top() {
        return front;
    }
    
    bool empty() {
        return sz==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */