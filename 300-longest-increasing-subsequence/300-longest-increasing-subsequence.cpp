class Solution {
public:
    
//     int LIS_top(int i, int prev_i, vector<int>& nums, vector<int>&dp) {
//         if(i >= nums.size())
//             return 0;
        
//         if(dp[prev_i+1] != -1)
//             return dp[prev_i+1];
        
//         int the_choosen_one = 0;
//         int not_choosen = LIS_top(i+1, prev_i, nums, dp);
        
//         if(prev_i == -1 || nums[i] > nums[prev_i])
//             the_choosen_one = 1 + LIS_top(i+1, i, nums, dp);
        
//         return dp[prev_i+1] = max(not_choosen, the_choosen_one);
//     }
    
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n,-1);
    //     return LIS(0, -1, nums, dp);
    // }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,1);
//         int ans=1;
//         for(int i=0; i<n; i++)
//             for(int j=0; j<i; j++){
//                 if(nums[i] > nums[j])
//                     dp[i] = max(dp[i], 1+dp[j]);
//                     ans = max(ans, dp[i]);
//             }
//         return ans;
        
//     }    
    
    
     int lengthOfLIS(vector<int>& nums) {
        return LIS(nums);
    } 
    
    
    int LIS(vector<int>&A){
        vector<int>v{A[0]};
        int n = A.size();
        for(int i=1; i<n; i++){
            if(A[i]>*(v.end()-1))
                v.push_back(A[i]);
            else{
                auto it = lower_bound(v.begin(), v.end(), A[i]);
                v[it-v.begin()] = A[i];      
            }
            
            
            
        }       
        return v.size();
    }
    
    
};