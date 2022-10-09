class Solution {
public:
    
    
    vector<vector<vector<int>>> dp;
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        dp.resize(sz, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        return solve(sz-1, m, n, strs);
        
    }
    
    int solve(int i, int nzeroes, int nones, vector<string>& strs){
        if(i<0)return 0;
        if(nzeroes<0 || nones<0)return 0;
        
        if(dp[i][nzeroes][nones] != -1) return dp[i][nzeroes][nones];
        
        int zeroes = count(strs[i].begin(), strs[i].end(), '0');
        int ones = strs[i].size()-zeroes;
        
        int choosen = 0;
        if(zeroes<=nzeroes and ones<=nones)
            choosen = 1 + solve(i-1, nzeroes-zeroes, nones-ones, strs);
        int notchoosen = solve(i-1, nzeroes, nones, strs);
        
        return dp[i][nzeroes][nones] = max(choosen, notchoosen);
        
    }
};