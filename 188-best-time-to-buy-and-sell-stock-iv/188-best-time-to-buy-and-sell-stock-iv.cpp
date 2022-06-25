class Solution {
public:
    int n;
    vector<int>stock;
    int DP[10005][105][2]; //n,k,hold;
    
    int solve(int i, int trans, bool hold){
        if(i>=n || trans<=0)
            return 0;

        
        if(DP[i][trans][hold]!=-1)
            return DP[i][trans][hold];
        
        if(hold==true)
            return DP[i][trans][hold] = max( solve(i+1, trans, true), stock[i]+solve(i+1,trans-1, false) );
        
        return DP[i][trans][hold] = max( solve(i+1,trans,false), -stock[i]+solve(i+1, trans, true) );
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        stock = prices;
        memset(DP, -1, sizeof(DP));
        
        int val =  solve(0,k,false);
        
        
        return val;

    }
};