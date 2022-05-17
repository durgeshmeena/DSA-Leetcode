class Solution {
public:
    string s,t;
    int n,m;
    vector<vector<int>>dp;
    
    int sol(int i, int j){
        if (i<1)
            return dp[i][j] = 1;
        
        if (j<1 )
            return dp[i][j] = 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if (t[i-1] == s[j-1]){
            return dp[i][j] = sol(i-1, j-1)+sol(i, j-1);
        }
        else {
            return dp[i][j] = sol(i, j-1);
        }
        
        
    }
    
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        n = s.size();
        m = t.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        
        return sol(m, n);
    }
};