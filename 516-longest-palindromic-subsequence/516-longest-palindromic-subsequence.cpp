class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // string s2 = s;
        // reverse(s2.begin(), s2.end());
        // return lcs(s, s2);
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i=0;i<n; i++)
            dp[i][i] = 1;
        
        for(int i=n-2; i>=0; i--)
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        
        return dp[0][n-1];
        
        
    }
    
    
//     =========== using LCS ==============
    
    int lcs(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                
            }
        return dp[n1][n2];
    }
};