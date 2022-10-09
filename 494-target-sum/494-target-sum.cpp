class Solution {
public:
    
    unordered_map<string, int> dp;
    
    int dfs(int i, int target, vector<int>& nums){
        if(i>=nums.size()){
            return target==0;
        }
        string key = to_string(i)+"#"+to_string(target);
        
        if(dp.find(key) != dp.end())return dp[key];
        
        return dp[key] = dfs(i+1, target-nums[i], nums) + dfs(i+1, target+nums[i], nums);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
      
        
        return dfs(0, target, nums);
        
    }
};