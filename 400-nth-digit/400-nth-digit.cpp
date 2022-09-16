class Solution {
public:
    
    
    long long digits(int num){
        string s = to_string(num);
        int len = s.size();
        long long sum=0;
        for(int i=1; i<len; i++){
            sum += 1ll*9*pow(10, i-1)*i;
        }
        num -= pow(10, len-1);
        num++;
        sum += 1ll*num*len;
        
        return 1ll*sum;
    }
    
    
    int findNthDigit(int n) {
        int l=1, r=n;
        // while(digits(r)<n)r = 1ll*r*r;
        // l = 1;
        cout << "l1="<<l<< ", r1="<<r <<"\n";

        while(l<r){
            int mid = l+(r-l)/2;
            if(digits(mid) < 1ll*n)
                l = mid+1;
            else
                r = mid;
        }
        
        n -= digits(l-1);
        
        string s = to_string(l);
        
        // cout << "l="<<l<<"\n";
        // cout << "nn="<<n;
        return s[n-1]-'0';
        // return 0;
        
    }
}; 