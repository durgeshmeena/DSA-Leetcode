class Solution {
public:
    vector<int>arr;
    vector<int>dp;
    
    int LIS(int i, int prev_i){
        if(i<0)
            return 0;
        
        if(dp[prev_i+1]!=INT_MIN)
            return dp[prev_i+1];
        
        if(prev_i == -1 || arr[i] < arr[prev_i])
            return dp[prev_i+1] = max(1+LIS(i-1, i), LIS(i-1, prev_i));
        return dp[prev_i+1] = LIS(i-1, prev_i);
        
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        this->arr = nums;
        int n = nums.size();
        dp.resize(n+1, 1);
        // return LIS(nums.size()-1, -1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]>arr[j])
                    dp[i] = max(1+dp[j], dp[i]);
            }
        }
        return *max_element(dp.begin(), dp.end());
        
        
    }
};