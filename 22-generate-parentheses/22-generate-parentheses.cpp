class Solution {
public:
    
    vector<string>v;
    
    void GP(int o, int c, string OP){
        if(o > c)
            return;
        if(o == 0){
            while(c--)
                OP += ")";
            v.push_back(OP);
            return;
        }
        
        GP(o-1, c, OP+"(");
        GP(o, c-1, OP+")");
    }
    
    vector<string> generateParenthesis(int n) {
        
        GP(n-1, n, "(" );
        return v;
        
    }
};