class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>dp(k+2, vector(n,INT_MAX));
        
        for(int i=0;i<=k+1;i++)dp[i][src]=0;
        
        for(int i=1;i<=k+1;i++){
            for(auto x:flights){
                if(dp[i-1][x[0]] != INT_MAX){
                    dp[i][x[1]] = min(dp[i][x[1]], dp[i-1][x[0]]+x[2]);
                }
            }
        }
        
        return dp[k+1][dst] == INT_MAX? -1: dp[k+1][dst];
        
    }
    
    
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int,int>>>adj(n);
//         priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
//         vector<int>lastK(n);
        
//         for(auto x:flights){
//             adj[x[0]].push_back({x[1],x[2]});
//         }
        

//         pq.push({0,src,k+1});
        
//         while(!pq.empty()) {
//             auto it = pq.top();
//             pq.pop();
//             int cost, node, stop;
//             tie(cost, node, stop) = it;
//             if(node==dst)
//                 return cost;
            
//             if(stop < lastK[node])continue;
//             lastK[node]=stop;
            
//             if(stop>0){
//                 for(auto v:adj[node])
//                     pq.push({cost+v.second, v.first, stop-1});
//             }
            
            
//         }
//         return -1;
         
//     }
    
};