class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        for(int i=0;i<n; i++)
            dp[i][i] = true;
        
        // for(int i=0; i<n; i++)
        //     for(int j=i+1; j<n; j++)
        //         dp[i][j]=false;
        
        for(int i=n-2; i>=0; i--)
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] and( i>j-2 || dp[i+1][j-1]==true))
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        
        // return dp[0][n-1]; "fcabadf" "abc"
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 cout << dp[i][j] <<" ";
//             }
//             cout <<"\n";
//         }
            
        
        int cnt=0;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                cnt += dp[i][j];
        
        
        return cnt;
        
    }
};