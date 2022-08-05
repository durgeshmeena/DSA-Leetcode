class Solution {
public:
    
    int dp[50][50];
    int maxi[50][50];
    
    int solve(int i, int j, vector<int>& arr){
        if(j<=i)return 0;
        else if(j-i == 1) return arr[i]*arr[j];
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int tmp = INT_MAX;
        for(int k=i; k<j; k++){
            tmp = min(tmp, solve(i,k, arr)+solve(k+1,j, arr)+maxi[i][k]*maxi[k+1][j]);
        }
        return dp[i][j] = tmp;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
    
        memset(dp, 0, sizeof(dp));
        memset(maxi, 0, sizeof(maxi));
        
        for(int i=0; i<n; i++){
            maxi[i][i] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[i][j] = max({maxi[i][j], maxi[i][j-1], arr[j]});
            }
        }
            
        
        // for (int l = 1; l < n; ++l) {
        //    for (int i = 0; i < n - l; ++i) {
        //        int j = i + l;
        //        dp[i][j] = INT_MAX;
        //        for (int k = i; k < j; k++) {
        //            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + maxi[i][k] * maxi[k+1][j]);
        //        }
        //    }
        // }
        // return dp[0][n-1];
        
        
        for (int i = n-2; i >= 0; i--) {
           for (int j = i+1; j < n ; j++) {
               int tmp = INT_MAX;
               for (int k = i; k < j; k++) {
                   tmp = min(tmp, dp[i][k] + dp[k+1][j] + maxi[i][k] * maxi[k+1][j]);
               }
               dp[i][j] = tmp;
           }
        }
        return dp[0][n-1];
        
        // return solve(0, n-1, arr);

    }
};