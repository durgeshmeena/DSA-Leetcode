class Solution {
public:
    int DP[45];
    int solve(int n){
        if(n<3)
            return n;
        if(DP[n-1] != -1)
            return DP[n-1];
        
        return DP[n-1] = solve(n-1) + solve(n-2);
    }
    
    int climbStairs(int n) {
        memset(DP, -1, sizeof(DP));
        
        return solve(n);
    }
};