class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1,v2;
        vector<vector<int>> dp(n);
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
            dp[i].push_back(nums[i]);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    v1 = dp[j];
                    v1.push_back(nums[i]);
                    if(dp[j].size()>=dp[i].size()){
                        dp[i] = v1;
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0; i<n; i++){
            if(dp[i].size()>dp[maxi].size())
                maxi = i;
        }
        
        return dp[maxi];
            
            
        
        
        
    }
};