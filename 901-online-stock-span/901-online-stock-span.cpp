class StockSpanner {
public:
    
    int day;
    stack<int> st;
    vector<int>v;
    StockSpanner() {
        day = 0;
    }
    
    int next(int price){

        v.push_back(price);
        
        while(st.size() and price >= v[st.top()]){
            st.pop();
        }
        
        
        int val;
        if(st.empty())
            val = day+1;
        else
            val = day-st.top();
        
        st.push(day++);
        return val;
        
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */