class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        for(int i=0; i<s.size(); i++){
            string ch = "";
            ch += s[i];
            
            if(ch=="]"){
                string s="";
                while(st.top()!="["){
                    s = st.top()+s;
                    st.pop();
                }st.pop();
                string repp = "";
                while(!st.empty() and st.top()!="[" and !isalpha(st.top()[0])){
                    repp = st.top()+repp;
                    st.pop();
                }
                int rep = stoi(repp);
                string ss = s;
                while(--rep) ss += s;
                st.push(ss);
            }
            else{
                st.push(ch);
            }



        }
        string res = "";
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
        
        
    }
};