class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(0, 0, s, p);
    }
    
    bool solve(int i, int j, string &s, string &p){
        int sz = s.size();
        if(j==p.size())
            return i==sz;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(p[j]=='*'){
            return dp[i][j] = solve(i, j+1, s, p) || (i<sz && (solve(i+1, j+1, s, p) || solve(i+1, j, s, p)));
        }
        if (i<sz && (p[j]=='?' || s[i]==p[j]))
            return dp[i][j] = solve(i+1, j+1, s, p);
        
        return dp[i][j] = 0;
    }
};