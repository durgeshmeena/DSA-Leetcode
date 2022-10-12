class Solution {
public:
    
    vector<int> prices;
    vector<vector<vector<int>>> dp;
    
    int maxProfit(int k, vector<int>& prices) {
        this->prices = prices;
        int n = prices.size();
        dp.resize(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return solve(0, 1, k);
        
    }
    
    int solve(int i, int buy, int k){
        if(i>=prices.size() || k<=0)return 0;
        
        if(dp[i][k][buy] != -1)return dp[i][k][buy];
        
        if(buy){
            return dp[i][k][buy] = max( solve(i+1, 1, k), -prices[i] + solve(i+1, 0, k) );
        }
        
        return dp[i][k][buy] = max( solve(i+1, 0, k), prices[i] + solve(i+1, 1, k-1) );
    }
};