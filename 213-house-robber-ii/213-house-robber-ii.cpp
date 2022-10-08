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
    
    int rob1_td(int i, vector<int> &v, vector<int> &dp){
        if(i==0) return dp[i] = v[0];
        else if(i==1) return dp[i] = max(v[0], v[1]);
        
        if(dp[i]!=-1)return dp[i];
        
        return dp[i] = max(rob1_td(i-1, v, dp), v[i]+rob1_td(i-2, v, dp));
            
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> v1(nums.begin(), nums.end()-1), v2(nums.begin()+1, nums.end());
        
        vector<int> dp(n-1, -1);
        int val1 = rob1_td(n-2, v1, dp);
        
        dp.clear();
        dp.resize(n-1, -1);
        // for(auto x:dp)cout << x <<" ";
        // cout <<"\n";
        int val2 = rob1_td(n-2, v2, dp);
        // for(auto x:dp)cout << x <<" ";
        return max(val1, val2);

    }
};