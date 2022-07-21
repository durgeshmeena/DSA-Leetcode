class Solution {
public:
    
    vector<vector<int>>dp;
    
    int solve(int target, int i, vector<int> &coins){
        if(target==0)return 0;
        else if(i==coins.size())return INT_MAX-1;
        
        if(dp[target][i] != -1)
            return dp[target][i];
        
        int choosen = INT_MAX;
        if(coins[i]<=target)
            choosen = 1+solve(target-coins[i], i, coins);
        int notChoosen = solve(target, i+1, coins);
        return dp[target][i] =  min(choosen, notChoosen);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, vector<int>(coins.size()+1, -1));
        int val = solve(amount, 0, coins);
        if(val >= INT_MAX-2)
            return -1;
        return val;
        
    }
};