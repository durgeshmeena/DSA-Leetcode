class Solution {
public:
    
    int rob1(vector<int>& v){
        int n = v.size();
        if(n==1)return v[0];
        vector<int> dp(n);
        dp[0] = v[0];
        dp[1] = max(v[0], v[1]);
        
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+v[i]);
        }
        return dp[n-1];
    }
    
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> v1(nums.begin(), nums.end()-1), v2(nums.begin()+1, nums.end());
        int val1 = rob1(v1);
        int val2 = rob1(v2);
        
        return max(val1, val2);

    }
};