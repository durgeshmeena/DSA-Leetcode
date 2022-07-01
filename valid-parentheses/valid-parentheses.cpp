class Solution {
public:
    
    
    
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        
        auto isOpen = [](char c){ 
            if(c=='(' || c=='{' || c=='[')
                return true;
            return false;
        };
        
        auto mirror = [](char c){
            if(c == ')') return '(';
            else if(c == '}') return '{';
            return '[';
        };
        
        
        for(int i=0; i<n; i++){
            if(isOpen(s[i]))
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                
                if(st.top() == mirror(s[i])){
                    st.pop();
                }else
                    return false;
            }
                
        }
        
        return st.empty();
        
        
        
        
    }
};