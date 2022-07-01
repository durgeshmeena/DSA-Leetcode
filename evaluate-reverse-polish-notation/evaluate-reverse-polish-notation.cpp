class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        
        auto oper = [](string s){
            if(s=="+" || s=="-" || s=="*" || s=="/")
                return true;
            return false;
            
        };
        
        auto eval = [](int a, int b, string s){
            if(s=="+")
                return a+b;
            else if(s=="-")
                return a-b;
            else if(s=="*")
                return a*b;
            return a/b;
        };
        
        for(int i=0; i<n; i++){
            
            if(oper(tokens[i])){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                int val = eval(a, b, tokens[i]);
                st.push(val);
            }else{
                st.push(stoi(tokens[i]));
            }
            
            
        }
        
        return st.top();
        
    }
};