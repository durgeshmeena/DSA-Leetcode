class Solution {
public:
    vector<int>dp;
    vector<int>cost;
    
    int solve(int i){
        if(i<0) return 0;
        if(dp[i] != -1)
            return dp[i];
        
        return dp[i] = cost[i] + min(solve(i-1), solve(i-2));
        
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp = vector<int>(n, -1);
        this->cost = cost;
        return min(solve(n-1), solve(n-2));
    }
};