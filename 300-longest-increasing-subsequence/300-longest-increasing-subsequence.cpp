class Solution {
public:
    
    int LIS(int i, int prev_i, vector<int>& nums, vector<int>&dp) {
        if(i >= nums.size())
            return 0;
        
        if(dp[prev_i+1] != -1)
            return dp[prev_i+1];
        
        int the_choosen_one = 0;
        int not_choosen = LIS(i+1, prev_i, nums, dp);
        
        if(prev_i == -1 || nums[i] > nums[prev_i])
            the_choosen_one = 1 + LIS(i+1, i, nums, dp);
        
        return dp[prev_i+1] = max(not_choosen, the_choosen_one);
    }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n,-1);
    //     return LIS(0, -1, nums, dp);
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], 1+dp[j]);
                    ans = max(ans, dp[i]);
            }
        return ans;
        
    }    
    
    
    
};