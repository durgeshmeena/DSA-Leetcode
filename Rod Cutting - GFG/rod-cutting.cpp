//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    vector<int> dp;
  
    int solve(int len, int arr[], int n){
        if(len<=0)return 0;
        
        if(dp[len] != -1)return dp[len];
        
        int ans = arr[len-1];
        for(int i=1; i<len; i++){
            int res = solve(i, arr, n) + solve(len-i, arr, n);
            ans = max(ans, res);
        }
        return dp[len] = ans;
    }
    
    int cutRod(int price[], int n) {
        //code here
        dp.resize(n+1, -1);
        return solve(n, price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends