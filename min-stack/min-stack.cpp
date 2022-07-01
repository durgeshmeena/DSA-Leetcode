class MinStack {
private:
    vector<int>data;
    vector<int>minStack = {INT_MAX};
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push_back(val);
        
        if(val <= minStack.back())
            minStack.push_back(val);
    }
    
    void pop() {
        if(data.size()<1)
            return;
        int val = data.back();
        data.pop_back();
        
        if(val == minStack.back())
            minStack.pop_back();
    }
    
    int top() {
        if(data.size()>0)
            return data.back();
        return -1;
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */