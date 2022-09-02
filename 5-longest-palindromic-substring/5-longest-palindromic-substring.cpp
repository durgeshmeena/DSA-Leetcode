class Solution {
public:
    string longestPalindrome(string A) {
        int n = A.size();
        if(n==1)return A;


        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int k=0; k<n; k++)dp[k][k]=1;

        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(A[i] == A[j] and ( dp[i+1][j-1]==j-i-1 || j-i==1  )){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }


        int len = dp[0][n-1];

        int i=0, j=n-1;
        while(i<n and j>0 and  len == max(dp[i][j-1], dp[i+1][j])  ){
            if(dp[i][j] == dp[i][j-1]){
                j--;
            }
            else{
                i++;
            }
        }

        string s = A.substr(i, len);
        cout << s << endl;    
        return s;        
    }
};