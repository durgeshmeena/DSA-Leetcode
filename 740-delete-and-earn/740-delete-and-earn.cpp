class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> val;
        for(auto e : nums)
            val[e] += e;
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        
        int maxi = v.back();
        
        vector<int> dp(maxi+2, 0);
        dp[0] = 0;
        dp[1] = val[1];
        
        for(int i=2; i<=maxi; i++){
            dp[i] = max(dp[i-1], val[i]+dp[i-2]); 
        }
        
        return dp[maxi];
        
    }
};