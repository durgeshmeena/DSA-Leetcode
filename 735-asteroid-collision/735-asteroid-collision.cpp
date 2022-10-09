class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        
        for(auto x:ast){
            if(x>0)st.push(x);
            else{
                while(!st.empty() and st.top()>0 and abs(x)>st.top())st.pop();
                if(st.empty() || st.top()<0)st.push(x);
                else if(st.top() == abs(x))st.pop();
            }
        }
        
        vector<int>v(st.size());
        for(int i=st.size()-1; i>=0; i--){
            v[i] = st.top();
            st.pop();
        }
        
        return v;
        
    }
};