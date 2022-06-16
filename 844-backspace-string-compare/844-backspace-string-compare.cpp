class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        auto solv = [&](string& s1){
            string str = "";
            
            for(auto x:s1){
                if(x=='#'){
                    if(str.length())
                        str.pop_back();
                }
                else
                    str+=x;
            }
            return str;
        };
        
        return solv(s)==solv(t);
    }
};