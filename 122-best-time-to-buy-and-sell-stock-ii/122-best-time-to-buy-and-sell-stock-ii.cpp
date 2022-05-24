class Solution {
public:
    
    int profit(int i, bool holding, vector<int>& prices, vector<vector<int>>& dp){
        if(i>=prices.size())
            return 0;
        
        if(dp[i][holding] != -1)
            return dp[i][holding];
        
        if(holding)
            dp[i][holding] =  max(prices[i] + profit(i+1, 0, prices, dp), profit(i+1, 1, prices, dp));
        
        else
            dp[i][holding] =  max( -prices[i] + profit(i+1, 1, prices, dp), profit(i+1, 0, prices, dp));
        
        return dp[i][holding];
           
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        int val = profit(0, 0, prices, dp );
        
        return *max_element(dp[0].begin(), dp[0].end());
    }
};