class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ls;
        int n = nums.size();
        vector<vector<vector<int>>> dp(n);
        for(int i=0; i<n; i++)
            dp[i].push_back({nums[i]});
        
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++){
                if(nums[j]<=nums[i]){
                    for(auto v:dp[j]){
                        auto v1 = v;
                        v1.push_back(nums[i]);
                        dp[i].push_back(v1);
                        ls.insert(v1);
                    }
                }
            }
        
        
        vector<vector<int>> ans(ls.begin(), ls.end());
        return ans;
    }
};