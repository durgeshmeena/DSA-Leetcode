class Solution {
public:
    
    int jump(vector<int>& nums) {
        int s = nums.size();
        if (s == 1)return 0;
        else if (s == 2)return 1;
        
        int cnt = 1;
        vector<int>dp(s, INT_MAX);
        
        for (int i=s-2; i>=0; i--) {
            
            if (nums[i] == 0) cnt++;
            
            else if (nums[i] >= cnt) {
                dp[i] = 1;
                cnt++;
            }
            else {
                int min_ = INT_MAX-1;
                for (int k=i+nums[i]; k>i; k--) {
                    min_ = min(min_, dp[k]);
                }
                dp[i] = 1+min_;
                cnt++;
            }
        }
        
        
        return dp[0];
    }
};