class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cur_sum = 0;
        int max_sum = nums[0];
        
        for (int i=0; i<nums.size(); i++) {
            
            if (cur_sum+nums[i]<0)cur_sum=0;
            
            cur_sum = max(nums[i], cur_sum+nums[i]);
            
            max_sum = max(cur_sum, max_sum);
            
        }
        return max_sum;
        
    }
};