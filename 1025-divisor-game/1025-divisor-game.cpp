class Solution {
public:
    
    unordered_map<int, bool> dp;
    
    bool divisorGame(int n) {
       
        
       return n%2==0;
        
    }
    
    
//     bool solve(int n){
//         if(n==1)return false;
//         else if(n==2)return true;
        
//         if(dp.find(n) != dp.end())return dp[n];
        
//         for(int i=1; i<n-1; i++){
//             if(n%i==0 and solve(n-i))return true;
//         }
//         return dp[n] = false;
        
//     }
    
};