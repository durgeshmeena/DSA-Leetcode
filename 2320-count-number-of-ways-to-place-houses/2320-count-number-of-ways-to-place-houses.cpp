class Solution {
public:
    
    int M = 1e9 + 7;
    
    int rob(int n){
        
        if(n==1)
            return 1;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<n; i++){
            dp[i] = (dp[i-1] + 1+dp[i-2])%M;
        }
            
        
        return dp[n-1]%M;
        
    }
    
    
    int countHousePlacements(int n) {
        
        int val = rob(n);
        
        return (1ll*((val+1)%M)*((val+1)%M))%M;
        
        
    }
};