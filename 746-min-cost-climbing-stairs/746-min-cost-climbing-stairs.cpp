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
        dp = vector<int>(n);
        // this->cost = cost;
        // return min(solve(n-1), solve(n-2));
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    
};