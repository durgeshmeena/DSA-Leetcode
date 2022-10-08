class Solution {
public:
    
    
    vector<vector<int>>dp;
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1, vector<int>(amount+1, -1));
        
        int val = solve(n-1, amount, coins);
        if(val >= 1e9)return -1;
        
        return val;
        
    }
    
    int solve(int i, int amount, vector<int>& coins){
        if(amount==0)return dp[i][amount]=0;
        if(i<0) return 1e9;
        
        if(dp[i][amount] != -1)return dp[i][amount];
        
        
        if(coins[i]<=amount)
            return dp[i][amount] = min(1+solve(i, amount-coins[i], coins), solve(i-1, amount, coins));
        return dp[i][amount] = solve(i-1, amount, coins);
    }
};