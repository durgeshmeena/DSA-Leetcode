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
        
        return solve(n-1);
        
    }
};