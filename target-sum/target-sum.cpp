class Solution {
public:
    int ways = 0;
    
    void DFS(int i, int sum, vector<int>& nums, int target){
        if(i >= nums.size()){
            ways += sum == target;
            return;
        }
        DFS(i+1, sum+nums[i], nums, target);
        DFS(i+1, sum-nums[i] , nums, target);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        DFS(0,0,nums,target);
        return ways;
    }
};