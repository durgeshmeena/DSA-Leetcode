class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x;
        while(l<r){
            int mid = l + (r-l)/2;
            if(1ll*mid*mid < x)
                l = mid+1;
            else
                r = mid;
        }
        if(1ll*l*l == x)return l;
        return l-1;
        
    }
};