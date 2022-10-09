class Solution {
public:
    
    void dfs(int i, int target, int &count, vector<int>& nums){
        if(i>=nums.size()){
            if(target==0)count++;
            return;
        }
        dfs(i+1, target-nums[i], count, nums);
        dfs(i+1, target+nums[i], count, nums);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int count=0;
        dfs(0, target, count, nums);
        return count;
    }
};