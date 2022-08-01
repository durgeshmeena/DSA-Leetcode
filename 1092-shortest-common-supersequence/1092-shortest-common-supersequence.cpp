class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        
        for(int i=1; i<=n1; i++)
            for(int j=1; j<=n2; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                
            }
        
        string str = "";
        int i=n1, j=n2;
        while(i>0 and j>0){
            if(s1[i-1] == s2[j-1]){
                str += s1[i-1];
                i--, j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    str += s2[j-1];
                    j--;
                }   
                else{
                    str += s1[i-1];
                    i--;
                }
            }
        }
        reverse(str.begin(), str.end());
        
        str = s1.substr(0,i) + s2.substr(0,j) + str;
        return str;
        
        
    }
};