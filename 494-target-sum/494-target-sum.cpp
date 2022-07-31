class Solution {
public:
    int t,n, res;
    
    void DFS(int i, int sum, vector<int>& nums){
        if(i==n){
            if(sum==t)res++;
            return;
        }
        
        DFS(i+1, sum+nums[i], nums);
        DFS(i+1, sum-nums[i], nums);
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        n = nums.size();
        res=0;
        DFS(0,0, nums);
        return res;
    }
};