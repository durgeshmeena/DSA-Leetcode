class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
            x = 1/x;
        else if(n==0)
            return 1;
        
        double p = x;
        double r = 1.0;
        while(n){
            if(n%2 != 0)
                r = p*r;
            p = p*p;
            n/=2;
        }
        
        return r;
        
    }
};