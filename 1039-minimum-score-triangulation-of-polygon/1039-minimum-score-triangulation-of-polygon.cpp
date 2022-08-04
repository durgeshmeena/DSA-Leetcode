class Solution {
public:
    
    int dp[100][100];
    
    int solve(int i, int j, vector<int>& values){
        if(j-i <= 1)
            return 0;
        else if(j-i == 2){
            return values[i]*values[i+1]*values[j];
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int tmp = INT_MAX;
        for(int k=i+1; k<j; k++){
            tmp = min(
                            tmp, 
                            solve(i,k,values)+
                            solve(k,j,values)+
                            values[i]*values[k]*values[j]
                        );
        }
        return dp[i][j] = tmp;
        
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, values);
        
    }
};