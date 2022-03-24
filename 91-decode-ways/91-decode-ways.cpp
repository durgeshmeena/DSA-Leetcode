class Solution {
public:

    
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);

        int size = s.size();
        if (size == 1) return s[0]-'0' == 0 ? 0 :1;
        
        dp[size] = 1;
        dp[size-1] = 1;
        
        if ( s[size-1] - '0' == 0 ) {
            if (s[size-2]-'0' > 2)return 0;
            
            dp[size-1] = 0;
            dp[size-2] = 1;
        }
        

        
        
        for ( int i = size-2; i>= 0; i--) {
            
            int val1 = s[i] - '0';
            int val2 = 10*(s[i]-'0') + s[i+1]-'0';
            
            if (val1 == 0) 
                dp[i] = 0;
        
             else 
                 dp[i] = (val1 > 0 )*dp[i+1] + (val2 > 0 and val2 < 27)*dp[i+2];
            
        }
        
        for (auto x:dp)
            cout << x << " ";
        
        return dp[0];
        
    }
};