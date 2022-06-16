class Solution {
public:
    
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n));
        int mx=1;
        
        for(int i=0; i<n; i++)
            dp[i][i]=1;
        
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j] ) {
                    if( j-i < 2 || dp[i+1][j-1]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                        mx = max(mx, dp[i][j]);
                    }
                        
                    
                }   
                else
                    dp[i][j] = 0;
            }
        }
        
        cout << mx << "\n";
        
        auto printLcs = [&](){
            string str="";            
            for(int i=0; i<n; i++)
                for(int j=n-1; j>=0; j--){
                    if(dp[i][j]==mx){
                        while(mx--){
                            str+=s[i];
                            i++,j--;
                        }
                        break;
                    }
                }
            return str;
            
        };
        
        return  printLcs();
       
    }
};