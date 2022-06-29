class Solution {
public:
    vector<vector<int>> dp;
    string s1, s2;
    string s = "";
    
    int lcs(int i, int j){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!= -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] =  1 + lcs(i-1, j-1);
        return dp[i][j] = max(lcs(i, j-1), lcs(i-1, j));
        
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        int n = s1.size();
        int m = s2.size();
        
        
        dp.resize(n, vector<int>(m, -1));
        
        return lcs(n-1, m-1);
        
    }
};