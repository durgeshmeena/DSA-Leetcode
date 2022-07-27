class Solution {
public:
    
    vector<int> dp;
    int n;
    vector<int>arr;
    
    int solve(int i){
        if(i==0)
            return dp[i] = arr[0];
        else if(i==1)
            return dp[i] = max(arr[0], arr[1]);
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i] = max(solve(i-1), solve(i-2)+arr[i]);
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        arr = nums;
        
        // return solve(n-1);
        
        dp[0] = arr[0];
        
        if(n==1)
            return dp[0];
        
        dp[1] = max(arr[0], arr[1]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
        }
        
        return dp[n-1];
        
    }
};