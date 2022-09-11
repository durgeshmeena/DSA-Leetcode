class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)return s;

        string str = "";
        str += s[0];
        vector<vector<bool>> dp(n, vector<bool>(n,0));

        for(int k=0; k<n; k++)dp[k][k]=true;

        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] and ( dp[i+1][j-1]==true || j-i==1  )){
                    dp[i][j] = true;
                    if(str.size() < j-i+1){
                        str = s.substr(i, j-i+1);
                    }
                    
                }
                else{
                    dp[i][j] = false;
                }
            }
        }        
        
        return str;
    }
};