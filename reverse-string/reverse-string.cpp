class Solution {
public:
    
    void reverse(int i, vector<char>& s){
        if(i==s.size())
            return;
        
        char c = s[i];
        reverse(i+1, s);
        s[s.size()-1-i] = c;
    }
    
    void reverseString(vector<char>& s) {
        reverse(0, s);
    }
};