class Solution {
public:
    int fib(int n) {
        int i_1 = 1;
        int i_2 = 0;
        int i_0=0;
        
        if (n<2)return n;
        for (int i=2; i<=n; i++) {
            i_0 = i_1 + i_2;
            
            i_2 = i_1;
            i_1 = i_0;
                  
        }
        return i_0;
    }
};