class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        vector<vector<long long>> dp(n2+1, vector<long long>(n1+1));
        for(int j=0; j<=n1; j++)
            dp[0][j] = 1;
        
        
        for(int i=1; i<=n2; i++)
            for(int j=1; j<=n1; j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                    if(dp[i][j]>= INT_MAX)
                        dp[i][j] = 0;
                }
                    
                else
                    dp[i][j] = dp[i][j-1];
            }
        
        // for(auto v:dp){
        //     for(auto x:v)
        //         cout << x <<" ";
        //     cout <<"\n";
        // }
        
        return dp[n2][n1];
        
    }
};