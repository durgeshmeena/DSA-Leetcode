class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
//         vector<pair<int,int>>adj[n];
        
//         for(auto v:edges){
//             adj[v[0]].push_back({v[1], v[2]});
//             adj[v[1]].push_back({v[0], v[2]});
//         }
        
//         auto bfs = [&](int src){
            
//             vector<int> dist(n, INT_MAX);
//             dist[src]=0;
//             priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//             pq.push({0, src});
            
//             while(pq.size()){
//                 auto ddist = pq.top().first;
//                 auto nnode = pq.top().second;
//                 pq.pop();
                
//                 for(auto x:adj[nnode]){
//                     if(dist[x.first] > ddist+x.second){
//                         dist[x.first] = ddist+x.second;
//                         pq.push({dist[x.first], x.first});
//                     }
//                 }
                
//             }
            
//             int count=-1;
//             for(int i=0; i<n; i++){
//                 if(dist[i] <= distanceThreshold)count++;
//             }
            
//             return count;
            
//         };
        
//         int dist = INT_MAX, node=-1;
//         for(int i=0; i<n; i++){
//             int ndist = bfs(i);
//             if(ndist <= dist){
//                 dist = ndist;
//                 node = i;
//             }
//         }
        
//         return node;
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(auto v:edges){
            dp[v[0]][v[1]] = v[2];
            dp[v[1]][v[0]] = v[2];
        }
        
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++){
                    if(i==j){
                        dp[i][j]=0;
                    }
                    else if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && dp[i][j] > dp[i][k]+dp[k][j]){
                        dp[i][j] = dp[i][k]+dp[k][j];
                    }
                }
        
        
        int dist=INT_MAX, node=-1;
        for(int i=0; i<n; i++){
            int count=-1;
            for(int j=0; j<n; j++){
                if(dp[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= dist){
                dist = count;
                node = i;
            }
        }
        
        return node;
            
        
    }
};