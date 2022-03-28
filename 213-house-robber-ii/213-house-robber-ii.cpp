class Solution {
public:
    
    int rob2(vector<int>nums) {
        int s = nums.size();
        vector<int>dp(s, 0);
        
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for (int i=2; i<s; i++) {
            
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        
        return dp[s-1];
        
    }    
    
    int rob(vector<int>& nums){
        int s = nums.size();
        if (s == 1)return nums[0];
        else if (s == 2)return max(nums[0], nums[1]);
    
        vector<int>v1(nums.begin(), nums.end()-1);
        vector<int>v2(nums.begin()+1, nums.end());

        
        int f_rob = rob2(v1);    
        int l_rob = rob2(v2);

        
        return max(f_rob, l_rob);
    }
    

};