class Solution {
public:
    
    int solve(int i, int j, int turn, vector<int>& piles,  vector<vector<vector<int>>> &dp){
        if(i == j){
            if(turn) return dp[i][j][turn] = piles[i];
            return dp[i][j][turn] = -piles[i];
        }
        
        if(dp[i][j][turn] != -1)
            return dp[i][j][turn];
        
        if(turn)
            return dp[i][j][turn] = max(piles[i]+solve(i+1, j, turn^1, piles, dp), piles[j]+solve(i, j-1, turn^1, piles, dp));
        
        return dp[i][j][turn] = max(-piles[i]+solve(i+1, j, turn^1, piles, dp), -piles[j]+solve(i, j-1, turn^1, piles, dp));

    }
    
    
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        
        return solve(0, n-1, 1, piles, dp) > 0;
        
        
    }
};