class Solution {
public:
    
    int rb(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][1] = nums[0];
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+nums[i]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0], nums[1]);
        
        vector<int> v(nums.begin()+1, nums.end());
        nums.pop_back();
        
        return max(rb(nums), rb(v));
    }
};