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
        // dp.resize(amount+1, vector<int>(coins.size()+1, -1));
        // int val = solve(amount, 0, coins);
        // if(val >= INT_MAX-2)
        //     return -1;
        // return val;
        
        int n = coins.size();
        dp.resize(n+1, vector<int>(amount+1));
        
        
        for(int j=1; j<=amount; j++)
            dp[0][j]=INT_MAX-1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j)
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        int val = dp[n][amount];
        return val <= INT_MAX-2 ? val : -1;
        
        
        
    }
};