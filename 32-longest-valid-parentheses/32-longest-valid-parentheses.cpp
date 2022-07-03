class Solution {
public:
    int longestValidParentheses(string s) {
        int len=0, maxLen=0;
        stack<int> st({-1});
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    len = i-st.top();
                
            }
            maxLen = max(len, maxLen);
        }
        
        return maxLen;
    }
};