class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int prev = prices[0];
        
        for(int i=1; i<prices.size(); i++){
            res = max(res, prices[i]-prev);
            if(prices[i] < prev)
                prev = prices[i];
        }
        
        return res;
        
    }
};