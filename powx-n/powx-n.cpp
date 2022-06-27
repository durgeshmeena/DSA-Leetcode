class Solution {
public:
    
    double x_n(double x, int n){
        if(n==0)
            return 1.0;
        else if(n==1)
            return x;
        
        if(n%2==0)
            return 1*pow( x_n(x, n/2) ,2);
        return x*pow( x_n(x, n/2) ,2);
        
        
    }
    
    double myPow(double x, int n) {
        if(x==0.000000 or x==1.000000)
            return x;
        if(n==0)
            return 1;
        
        if(n<0)
            x = 1/x;
        return x_n(x, n);
    }
};